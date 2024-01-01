#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int rear = -1;
int top = -1;

typedef struct
{
    int value;
} Element;

void enque(Element* arr, int x){
    if(rear==SIZE){
        printf("queue is full\n");
    } else{
        if(top==-1){
            top++;
        }
        arr[++rear].value = x;
    }
}

void deque(Element* arr){
    if(rear == top){
        printf("queue empty\n");
        rear = top = -1;
    } else{
        top++;
    }
}

void display(Element *arr){
    for(int i=top; i<=rear; i++){
        printf("%d ", arr[i].value);
    }
    printf("\n"); 
}


int main() {
    Element queue[SIZE];
    
    enque(queue, 1);
    enque(queue, 2);
    enque(queue, 3);
    display(queue);

    deque(queue);
    display(queue);

    enque(queue, 4);
    enque(queue, 5);
    enque(queue, 6);
    enque(queue, 7);
    display(queue);

    deque(queue);
    display(queue);

    return 0;
}
