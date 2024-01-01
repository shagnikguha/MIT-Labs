#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int top;
    char *stack;
} STACK;

void push(STACK *s, char n) {
    if (s->top == 49) {
        printf("Overflow\n");
        return;
    }
    s->stack[++(s->top)] = n;
}

void check(STACK *s, char strp[]) {
    int c = 0;
    int len = strlen(strp);
    for (int i = 0; i < len / 2; i++) {
        if (strp[len-i-1] != s->stack[i]) {
            c = 1;
            break;
        }
    }
    if (c == 1) {
        printf("Not Palindrome\n");
    } else {
        printf("Palindrome\n");
    }
}

int main(void) {
    STACK *s = (STACK *)malloc(sizeof(STACK));
    s->stack = (char *)malloc(50 * sizeof(char));
    s->top=-1;
    char str[50];
    printf("Enter word:\n");
    gets(str);
    for (int i = 0; i < strlen(str); i++) {
        push(s, str[i]);
    }
    check(s, str);
    free(s->stack);
    free(s);
    return 0;
}
