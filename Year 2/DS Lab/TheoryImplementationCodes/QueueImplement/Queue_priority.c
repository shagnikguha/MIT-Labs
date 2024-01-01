#include <stdio.h>
#include <stdlib.h>

#define size 7

int front = -1;
int rear = -1;

typedef struct{
    int val;
    int priority;
} Element;

void enqueue(Element *arr, int x, int p){
    if(front==(rear+1)%size){
        printf("Queue is full");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear = (rear+1)%size;
    arr[rear].val = x;
    arr[rear].priority = p;
    sortQ(arr);
}

void sortQ(Element *arr){
    Element temp;
    for(int i = front; i<=rear; i=(i+1)%size){
        for(int j = (i+1)%size; j<=rear; j=(j+1)%size){
            if(arr[i].priority>arr[j].priority)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void dequeue(Element *arr){
    if(front==-1){
        printf("Queue is empty");
        return;
    } else if(front == rear){
        front = rear = -1;
        return;
    }
    front = (front+1)%size;
}

void display(Element *arr){
    for(int i=front; i<=rear; i=(i+1)%size){
        printf("%d ", arr[i].val);
    }
    printf("\n");
}

int main(void) {
    Element arr[size]; // Circular queue array

    // Example usage:
    enqueue(arr, 1, 4);
    enqueue(arr, 2, 3);
    enqueue(arr, 3, 2);
    enqueue(arr, 4, 1);

    //display(arr); // Output: 1 (Priority: 4) 2 (Priority: 3) 3 (Priority: 2) 4 (Priority: 1)

    //sortQ(arr);

    display(arr); // Output: 4 (Priority: 1) 3 (Priority: 2) 2 (Priority: 3) 1 (Priority: 4)

    dequeue(arr);

    display(arr);
    
    enqueue(arr, 5, 5);

    //sortQ(arr);
    
    display(arr);


}