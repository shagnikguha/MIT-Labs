#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int ex;
  int val;
  struct Exponent *next;
} Exponent;

void insert(Exponent *arr, int x, int v){
    Exponent *current = (Exponent *)malloc(sizeof(Exponent));
    current = arr;
    Exponent *temp = (Exponent *)malloc(sizeof(Exponent));
    while(current->next!=NULL){
        current = current->next;
    }
    temp->val = v;
    temp->ex = x;
    temp->next=NULL;
    current = temp;
    free(temp);
}

void display(Exponent *arr){
    Exponent *current = arr;
    while(current->next != NULL){
        printf("%d^%d", current->val, current->ex);
        current = current->next;
        printf(" + ");
    }
    printf("\n");
}


int main(void){
    Exponent *eq1 = NULL;
    Exponent *eq2 = NULL;
    int i1, i2, v, x;
    printf("Enter the size of polynomial 1 and 2:\n");
    scanf("%d %d", &i1, &i2);
    for(int i=0;i<i1; i++){
        printf("Enter x and v:\n");
        scanf("%d %d", &x, &v);
        insert(eq1, x, v);
    }
    for(int i=0;i<i2; i++){
        printf("Enter x and v:\n");
        scanf("%d %d", &x, &v);
        insert(eq2, x, v);
    }
    display(eq1);
    display(eq2);
}
