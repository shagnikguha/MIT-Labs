#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int top;
    int *stack;
} STACK;

void push(STACK *s, int n){
    if(s->top==49){
        printf("Overflow\n");
        return;
    }
    s->stack[++(s->top)] = n;
}

void convert(STACK *s, int dec){
    while(dec!=0){
        push(s, dec%2);
        dec /= 2;
    }
}

void display(STACK *s){
    for(int i=s->top; i>=0; i--)
    {
        printf("%d", s->stack[i]);
    }
    printf("\n");
}

int main(void){
    STACK *s = (STACK *)malloc(sizeof(STACK));
    s->stack = (int *)calloc(50, sizeof(int));
    s->top = -1;
    int dec;
    printf("Enter Decimal number:\n");
    scanf("%d", &dec);
    convert(s, dec);
    printf("Binary Representation:\n");
    display(s);
    free(s->stack);
    free(s);
}