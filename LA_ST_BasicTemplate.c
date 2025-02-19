#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// defining the token structure
typedef struct token{
	char lexeme[64];
	int row;
	int col;
	char type[50];
} token;

typedef struct ST_Element{
	token tk;
	struct ST_Element *next;
} ST_Element;

// defining global variables
int row = 1, col = 1;

char specialsymbols[] = {'?', ';', ':', ',', '(', ')', '{', '}'};
char *Keywords[] = {"for", "if", "else", "while", "do", "break", "continue", "return", "int", "double", "float", "char", "long", "short", "sizeof", "typedef", "switch", "case", "struct", "const", "void", "exit"};
char arithmeticsymbols[] = {'*','+','-','/', '%'};
char relationalsymbols[] = {'>','<','!'};

ST_Element *Table = NULL; 	// initializing symbol table head as NULL

int isKeyword(char *str){
	int flag = 0;
	for(int i=0; i<sizeof(Keywords)/sizeof(char *); i++){
		if(strcmp(Keywords[i], str)==0){
			flag = 1;
			break;
		}
	}
	return flag;
}

int charBelongsTo(char c, char *list){	// checking whether char belongs to special or arithmetic or relational symbols
	int len;
	int flag = 0;
	if(list==specialsymbols){
		len = sizeof(specialsymbols)/sizeof(char);
	}
	if(list==arithmeticsymbols){
		len = sizeof(arithmeticsymbols)/sizeof(char);
	}
	if(list==relationalsymbols){
		len = sizeof(relationalsymbols)/sizeof(char);
	}
	for(int i=0; i<len; i++){
		if(c==list[i]){
			flag = 1;
		}
	}
	return flag;
}

void fillToken(token *tkn, char c, int row, int col, char *type) { // mainly for the single character values (for multi-char lexeme, we will edit it in getNextToken function)
	tkn->row = row;
    	tkn->col = col;
    	strcpy(tkn->type, type);
    	tkn->lexeme[0] = c;
    	tkn->lexeme[1] = '\0';
}

void ST_insert(token tkn){ // inserting into symbol table
	printf("Inserting token: lexeme=%s, type=%s, row=%d, col=%d\n", tkn.lexeme, tkn.type, tkn.row, tkn.col);
	ST_Element *current = Table;
	// check if entry already exists. If so, then exit function.
	while(current != NULL){
		if(strcmp(current->tk.lexeme, tkn.lexeme)==0){
			return;
		}
		current = current->next;
	}
	
	current = Table;
	// add new element
	ST_Element *new = (ST_Element *)malloc(sizeof(ST_Element));
	new->tk = tkn;
	new->next = NULL;
	
	if(current==NULL){
		Table = new;
	} else{
		while(current->next!= NULL){
			current = current->next;
		}
		current->next = new;
	}
}

void ST_display(){  // printing the sybol table
	ST_Element *current = Table;

 	printf("\n\tSYMBOL TABLE\n");
    	printf("Lexeme\t\tType\t\tRow\tColumn\n");
    	printf("------\t\t----\t\t---\t------\n");
    	
	while(current->next != NULL){
		printf("%-10s\t%-10s\t%d\t%d\n", current->tk.lexeme, current->tk.type, current->tk.row, current->tk.col);
		current = current->next;
	}
}

void newLine(){
	row += 1;
	col = 0;
}

token getNextToken(FILE *fptr){
	int c; 		// get c ready to store character
	int d;			// get d to store character after c
	//token tkn;		// get token ready
	int gotToken = 0;	// flag to stop loop
	
	// tkn.row = -1; 		// keeping so that loop in main function stops at EOF and does not get stuck in infinite loop
	struct token tkn = { "", -1, 0, "" };
	
	while(!gotToken && (c=fgetc(fptr))!=EOF){
		// ignoring coments
		if(c=='/'){
			d=fgetc(fptr);
			if(d=='*'){	
				int commentClosed = 0; 	// flag to see comment status
				while(!commentClosed && (d=fgetc(fptr))!=EOF){
					if(d=='*'){
						if ((d= fgetc(fptr))=='/') {
						    commentClosed = 1;
						} else {
						    fseek(fptr, -1, SEEK_CUR);
						}
						if(d=='\n'){
							newLine();
						}
					}
				}
			}
			else if(d=='/'){
				while((d=fgetc(fptr))!=EOF && d!='\n');
				newLine();
			}
			else {
				fseek(fptr, -1, SEEK_CUR);
			}
		}
		
		// igoring import headers
		if(c=='#'){
			while((d=fgetc(fptr))!=EOF && d!='\n');
			newLine();
		}
		
		// to check for special symbols
		if(charBelongsTo(c, specialsymbols)==1) {
			switch(c){
				case '?':
					fillToken(&tkn, c, row, col, "?");
					break;
				case ';':
					fillToken(&tkn, c, row, col, ";");
					break;
				case ':':
					fillToken(&tkn, c, row, col, ":");
					break;
				case ',':
					fillToken(&tkn, c, row, col, ",");
					break;
				case '(':
					fillToken(&tkn, c, row, col, "(");
					break;
				case ')':
					fillToken(&tkn, c, row, col, ")");
					break;
				case '{':
					fillToken(&tkn, c, row, col, "{");
					break;
				case '}':
					fillToken(&tkn, c, row, col, "}");
					break;
				default:
					break;
			}
			
			gotToken = 1;
			col += 1;
		}
		
		// handle arithmetic operators
		else if(charBelongsTo(c, arithmeticsymbols)==1) {
			switch(c){
				case '+':
					d=fgetc(fptr);
					if(d=='='){
						fillToken(&tkn, c, row, col, "+=");
						strcpy(tkn.lexeme, "+=");
						col += 2;
					} 
					else if(d=='+'){
						fillToken(&tkn, c, row, col, "++");
						strcpy(tkn.lexeme, "++");
						col += 2;
					} else	{
						fillToken(&tkn, c, row, col, "+");
						fseek(fptr, -1, SEEK_CUR);
						col += 1;
					}
					break;
				case '-':
					d=fgetc(fptr);
					if(d=='='){
						fillToken(&tkn, c, row, col, "-=");
						strcpy(tkn.lexeme, "-=");
						col += 2;
					} 
					else if(d=='-'){
						fillToken(&tkn, c, row, col, "--");
						strcpy(tkn.lexeme, "--");
						col += 2;
					} else	{
						fillToken(&tkn, c, row, col, "-");
						fseek(fptr, -1, SEEK_CUR);
						col += 1;
					}
					break;
				case '*':
					d=fgetc(fptr);
					if(d=='='){
						fillToken(&tkn, c, row, col, "*=");
						strcpy(tkn.lexeme, "*=");
						col += 2;
					} else	{
						fillToken(&tkn, c, row, col, "*");
						fseek(fptr, -1, SEEK_CUR);
						col += 1;
					}
					break;
				case '/':
					d=fgetc(fptr);
					if(d=='='){
						fillToken(&tkn, c, row, col, "/=");
						strcpy(tkn.lexeme, "/=");
						col += 2;
					} else	{
						fillToken(&tkn, c, row, col, "/");
						fseek(fptr, -1, SEEK_CUR);
						col += 1;
					}
					break;
				default:
					break;
			}
					
				gotToken = 1;			
		}
		
		// handle = and ==
		else if(c=='=') {
			d=fgetc(fptr);
			if(d=='='){
				fillToken(&tkn, c, row, col, "==");
				strcpy(tkn.lexeme, "==");
				col += 2;
			} else {
				fillToken(&tkn, c, row, col, "=");
				fseek(fptr, -1, SEEK_CUR);
				col += 1;
			}
			gotToken = 1;
		}
		
		// handle relational operations such as >=, >, <, <=, !=
		else if(charBelongsTo(c, relationalsymbols)==1) {
			switch(c){
				case '>':
					d=fgetc(fptr);
					if(d=='='){
						fillToken(&tkn, c, row, col, ">=");
						strcpy(tkn.lexeme, ">=");
						col += 2;
					} else	{
						fillToken(&tkn, c, row, col, ">");
						col += 1;
						fseek(fptr, -1, SEEK_CUR);
					}
					// gotToken = 1;
					break;
				case '<':
					d=fgetc(fptr);
					if(d=='='){
						fillToken(&tkn, c, row, col, "<=");
						strcpy(tkn.lexeme, "<=");
						col += 2;
					} else	{
						fillToken(&tkn, c, row, col, "<");
						col += 1;
						fseek(fptr, -1, SEEK_CUR);
					}
					break;
				case '!':
					d=fgetc(fptr);
					if(d=='='){
						fillToken(&tkn, c, row, col, "!=");
						strcpy(tkn.lexeme, "!=");
						col += 2;
					} else	{
						fillToken(&tkn, c, row, col, "!");
						col += 1;
						fseek(fptr, -1, SEEK_CUR);
					}
					break;
				default:
					break;
			}
				
				gotToken = 1;
		}
		
		// handle numbers
		else if(isdigit(c)){
			tkn.row = row;
			tkn.col = col++;
			tkn.lexeme[0] = c;
			int k = 1;
			while((d=fgetc(fptr))!=EOF && isdigit(d)) {
				col += 1;
				tkn.lexeme[k++] = d;
			}
			tkn.lexeme[k] = '\0';
			strcpy(tkn.type, "Number");
			
			gotToken = 1;
			fseek(fptr, -1, SEEK_CUR); // while will take one additional step forward
		}

		// handle keywords/identifiers
		else if(isalpha(c) || c=='_'){
			tkn.row = row;
			tkn.col = col++;
			tkn.lexeme[0] = c;
			int k = 1;
			while((d=fgetc(fptr))!=EOF && isalnum(d)){
				col += 1;
				tkn.lexeme[k++] = d;
			}
			tkn.lexeme[k] = '\0';
			if(isKeyword(tkn.lexeme)==1){
				strcpy(tkn.type, "Keyword");
			} else {
				strcpy(tkn.type, "Identifier");
			}
			
			gotToken = 1;
			fseek(fptr, -1, SEEK_CUR);
		}
		
		// handle string literals
		else if(c=='"'){
			tkn.row = row;
			tkn.col = col++;
			tkn.lexeme[0] = '"';
			int k = 1;
			while((d=fgetc(fptr))!=EOF && d!='"'){
				col++;
				tkn.lexeme[k++] = d;
			}
			tkn.lexeme[k++] = '"';
			tkn.lexeme[k] = '\0';
			col += 1;
			strcpy(tkn.type, "String Literal");
			
			gotToken = 1;
			//fseek(fptr, 1, SEEK_CUR); // not needed as variable is already pointing at '"' and pushing it one step forward will cause issues
		}
		
		// handle new line character
		else if(c=='\n'){
			newLine();
		}
		
		// handle space character
		else if(c==' '){
			col += 1;
		}
		// incase anything is left 
		else {
			col += 1;
		}
			
	}	
	
	// insert token into Symbol Table
	ST_insert(tkn);
	
	return tkn;
}

int main(){
	FILE *fptr;
	
	fptr = fopen("in.c", "r");
	
	token tkn;
    	int count = 1;
    	
    	while ((tkn = getNextToken(fptr)).row != -1)
        	printf( "%d. < %s , %d , %d, %s>\n", count++, tkn.type, tkn.row, tkn.col,tkn.lexeme);
    	
    	fclose(fptr);
    	
    	ST_display();
    	
    	return 0;
}			
