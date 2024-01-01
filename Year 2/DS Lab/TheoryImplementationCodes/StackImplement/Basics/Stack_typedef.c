#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int top;
    char *stack;
} STACK;

int isEmpty(STACK *s)
{
    if(s->top==-1)
    {
        return 1;
    } else{
        return 0;
    }
}

int isFull(STACK *s)
{
    if(s->top==4)
    {
        return 1;
    } else{
        return 0;
    }
}

void pop(STACK *s){
    if(isEmpty(s)){
        printf("Is empty.\n");
        return;
    }
    (s->top)--;
}

void push(STACK *s, char p){
    if(isFull(s))
    {
        printf("Is full.\n");
        return;
    }
    s->stack[++(s->top)] = p;
}

void display(STACK *s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack:\n");
    for(int i=s->top; i>=0; i--)
    {
        printf("%c\n", s->stack[i]);
    }
}

int main(void) {
    
    STACK *s;
    s->stack = (char *)calloc(5,sizeof(char));
    s->top = -1; 

    printf("Enter 1 top push.\n");
    printf("Enter 2 to pop.\n");
    printf("Enter 0 to display.\n");
    printf("Enter -1 to exit.\n");
    int a;
    char n;
    int l = 1;
    while(l!=0){
        printf("Enter command:\n");
        scanf("%d", &a);
        switch(a)
        {
        case 1:
            printf("Enter value to push:\n");
            scanf(" %c", &n);
            push(s, n);
            break;
        case 2:
            pop(s);
            break;
        
        case 0:
            display(s);
            break;

        case -1:
            printf("CLOSING\n");
            l=0;
            break;
        }
    }

    free(s->stack); // Free the allocated memory
}


