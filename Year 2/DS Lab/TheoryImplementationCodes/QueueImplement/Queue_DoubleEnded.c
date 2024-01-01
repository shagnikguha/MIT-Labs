#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int *q;
    int front1;
    int rear1;
    int front2;
    int rear2;
    int size;
} queue;

void insertF(queue *q, int x){
    if(q->rear1 + 1 == q->front2){
        printf("Queue is empty:\n");
        return;
    }
    if(q->front1==-1){
        q->front1++;
    }
    q->q[++(q->rear1)] = x;
}

void deleteF(queue *q){
    if(q->front1 == q->rear2){
        printf("Queue is empty");
        return;
    }
    if(q->front1 == -1){
        printf("Queue is empty");
        return;
    }
    q->front1++;
}

void insertB(queue *q, int x){
    if(q->front2 == q->rear1 + 1){
        printf("Queue is full");
        return;
    }
    if(q->rear2 == q->size){
        q->rear2--;
    }
    q->q[--(q->front2)] = x;
}

void deleteB(queue *q){
    if(q->front2 == q->rear1 +1){
        printf("Queue is empty");
        return;
    }
    if(q->rear2 == q->size){
        printf("Queue is empty");
        return;
    }
    q->front2++;
}

void display(queue *q){
    for(int i=q->front1; i<=q->rear1; i++){
        printf("%d ", q->q[i]);
    }
    for(int i=q->rear2; i>=q->front2; i--){
        printf("%d ", q->q[i]);
    }
    printf("\n");
}

void main(){
    queue *q = (queue *)malloc(sizeof(queue));
    q->front1=-1;
    q->rear1=-1;
    q->front2 = 8;
    q->rear2 = 8;
    q->size = 8;
    q->q = (int *)malloc(q->size * sizeof(int));
    insertF(q, 1);
    insertF(q, 2);
    insertB(q, 3);
    insertB(q, 5);
    deleteF(q);
    deleteB(q);
    insertB(q, 6);
    display(q);
}