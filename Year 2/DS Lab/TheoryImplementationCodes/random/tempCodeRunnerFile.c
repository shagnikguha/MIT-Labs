#include <stdlib.h>
#include <stdio.h>

#define size 7

int top = -1;
int rear = -1;

typedef struct{
    int value;
} Element;

void enqueue(Element* arr, int x){
    top = (top+1)%(size-1);
    if(top==rear){
        printf("Queue is full");
    } else{
        arr[top].value = x;
    }
}

void dequeue(Element *arr) {
    if (top == -1) {
        printf("Queue is empty\n");
    } else if (top == rear) {
        top = rear = -1;
    } else {
        top = (top + 1)%(size-1);
    }
}

void display(Element *arr){
    for(int i=top+1; i<=rear; i++){
        printf("%d ", arr[i].value);
    }
    printf("\n"); 
}

int main() {
    Element arr[size]; // Circular queue array

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

    return 0;
}