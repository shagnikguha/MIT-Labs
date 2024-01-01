#include <stdio.h>
#include <stdlib.h>

int top = -1;
int *stack;

int isEmpty()
{
    if(top==-1)
    {
        return 1;
    } else{
        return 0;
    }
}

int isFull()
{
    if(top==4)
    {
        return 1;
    } else{
        return 0;
    }
}

void pop(){
    if(isEmpty()){
        printf("Is empty.\n");
        return;
    }
    top--;
}

void push(int p){
    if(isFull())
    {
        printf("Is full.\n");
        return;
    }
    stack[++top] = p;
}

void display()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack:\n");
    for(int i=top; i>=0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main(void) {
    stack = (int *)calloc(5, sizeof(int));

    printf("Enter 1 top push.\n");
    printf("Enter 2 to pop.\n");
    printf("Enter 0 to display.\n");
    printf("Enter -1 to exit.\n");
    int a, n;
    int l = 1;
    while(l!=0){
        printf("Enter command:\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter value to push:\n");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        
        case 0:
            display();
            break;

        case -1:
            printf("CLOSING\n");
            l=0;
            break;
        }
    }

    free(stack); // Free the allocated memory
}


