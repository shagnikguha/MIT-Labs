#include <stdio.h>
#define size 10
int a[size];
int top1 = -1;
int top2 = size;

void push1(int x)
{
    if (top1 < top2)
    {
        a[++top1] = x;
        printf("%d pushed in stack 1\n", x);
    }
    else
        printf("stack full\n");
}

void push2(int x)
{
    if (top1 < top2)
    {
        a[--top2] = x; // Adjusted to top2--
        printf("%d pushed in stack 2\n", x);
    }
    else
        printf("stack full\n");
}

void pop1()
{
    if (top1 >= 0)
    {
        int x = a[top1--];
        printf("%d was popped from stack 1\n", x);
    }
    else
        printf("stack 1 empty\n");
}

void pop2()
{
    if (top2 < size - 1) // Adjusted to size - 1
    {
        int x = a[++top2]; // Adjusted to ++top2
        printf("%d was popped from stack 2\n", x);
    }
    else
        printf("stack 2 empty\n");
}

// Rest of the code remains the same...


void print1()
{
    printf("stack 1:\n");
    for (int i = top1; i >= 0; i--)
        printf("%d\t", a[i]);
    printf("\n");
}

void print2()
{
    printf("stack 2:\n");
    for (int i = top2; i < size; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

void main()
{
    int arr[size];
    int i, n;
    for (i = 0; i <= 6; i++)
        push1(i);
    for (i = 1; i <= 4; i++)
        push2(i);
    print1();
    print2();
    printf("pushing 11 in stack 1\n");
    push1(11);

    n = top1 + 1;
    while (n)
    {
        pop1();
        n--;
    }
    pop1();
}