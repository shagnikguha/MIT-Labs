#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

typedef struct
{
    char s[size];
    int top;
} STACK;

void push(STACK *s1, char x)
{
    s1->s[++(s1->top)] = x;
}

char pop(STACK *s1)
{
    return s1->s[s1->top--];
}

int isEmpty(STACK *s1){
    if(s1->top !=-1){
        return 0;
    } else{
        return 1;
    }
}

int Operand(char *c){
    int x =1;
    if (*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '$') {
        x = 0;
    }
    return x;
}

int pre(char x)
{
    switch (x)
    {
    case '#':
        return 0;
    case '(':
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '$':
        return 4;
    }
}

void main()
{
    STACK *s = (STACK *)malloc(sizeof(STACK));
    char symbol, post[50];
    s->top = -1;
    printf("Enter infix\n");
    scanf("%s", post);
    int n=0;
    while(post[n]!='\0')
    {
        if(Operand(&post[n])==0){
            printf("%c", post[n]);
        } else{
            while(pre(s->s[s->top])>=s->s[(s->top)-1]){
                printf("%c", pop(s));
            }
            push(s, post[n]);
        }
        n++;
    }
    while(!isEmpty(s)){
        printf("%c", pop(s));
    }
    free(s);

}