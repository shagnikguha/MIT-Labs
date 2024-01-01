#include <stdio.h>
#include <stdlib.h>

struct List{
    int x[10];
} List;


void dis(struct List *x){   // passing an array of structures
    for(int i = 0; i<2; i++){
        for(int j = 0; j<10; j++){
            printf("%d ", x[i].x[j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){
    struct List *x = (struct List *)malloc(2*sizeof(struct List)); // creating an array not an individual pointer like we do for our ADT
    for(int i = 0; i<2; i++){
        for(int j = 0; j<10; j++){
            x[i].x[j] = i+j;
        }
    }
    dis(x);
}