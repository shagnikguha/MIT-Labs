#include <stdlib.h>
#include <stdio.h>

#define size 7

int top = -1;
int rear = -1;

typedef struct{
    int value;
} Element;

void enqueue(Element* arr, int x){
    if((top==(rear+1)%size)){//||(top==0&&rear==size-1)){
        printf("Is full");
        return;
    }
    if(top==-1){
        top++;
    }
    rear = (rear+1)%size;
    arr[rear].value = x;
}

void dequeue(Element *arr) {
    if (top == -1) {
        printf("Queue is empty\n");
        return;
    } else if (top == rear) {
        top = rear = -1;
    } else {
        top = (top + 1)%(size);
    }
}

void display(Element *arr){
    for(int i=top; i<=rear; i=(i+1)%size){
        printf("%d ", arr[i].value);
    }
    printf("\n"); 
}

int main() {
    Element *arr = (Element *)malloc(size*sizeof(Element)); // Circular queue array

    // Example usage:
    enqueue(arr, 1);
    enqueue(arr, 2);
    enqueue(arr, 3);
    enqueue(arr, 4);

    display(arr); // Output: 1 2 3 4

    dequeue(arr);

    display(arr); // Output: 2 3 4

    enqueue(arr, 5);

    display(arr); // Output: 2 3 4 5

    free(arr);

    return 0;
}