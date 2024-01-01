#include <stdio.h>
#include <stdlib.h>

#define size 14

int front1 = -1;
int rear1 = -1;
int front2 = size;
int rear2 = size;

typedef struct {
    int value;
} Element;

void insertF(Element *arr, int x) {
    if (rear1 == front2 - 1) {
        printf("Queue 1 is full\n");
        return;
    }
    if (front1 == -1) {
        front1++;
    }
    rear1++;
    arr[rear1].value = x;
}

void insertB(Element *arr, int x) {
    if (front2 == rear1 + 1) {
        printf("Queue 2 is full\n");
        return;
    }
    if (rear2 == size) {
        rear2--;
    }
    front2--;
    arr[front2].value = x;
}

void deleteF(Element *arr) {
    if (front1 == -1) {
        printf("Queue 1 is empty\n");
        return;
    } else if (rear1 == front1) {
        rear1 = front1 = -1;
        printf("Queue 1 is empty\n");
        return;
    }
    front1++;
}

void deleteB(Element *arr) {
    if (rear2 == size) {
        printf("Queue 2 is empty\n");
    } else if (rear2 == front2) {
        rear2 = front2 = size;
        printf("Queue 2 is empty\n");
        return;
    }
    rear2--;
}

void display1(Element *arr) {
    for (int i = front1; i <= rear1; i++) {
        printf("%d ", arr[i].value);
    }
    printf("\n");
}

void display2(Element *arr) {
    for (int i = rear2; i >= front2; i--) {
        printf("%d ", arr[i].value);
    }
    printf("\n");
}

int main(void) {
    Element arr[size]; // Combined queue array

    // Example usage:
    insertF(arr, 1);
    insertF(arr, 2);
    insertB(arr, 3);
    insertB(arr, 4);

    display1(arr); // Output: 2 1
    display2(arr); // Output: 3 4

    deleteF(arr);
    deleteB(arr);

    display1(arr); // Output: 1
    display2(arr); // Output: 4

    insertF(arr, 5);
    insertB(arr, 6);

    display1(arr); // Output: 5 1
    display2(arr); // Output: 4 6

    return 0;
}
