#include <stdio.h>
#include <stdlib.h>

// Define the link structure
typedef struct link{
    int val;
    struct link *next;
} link;

// Declare a pointer to the head of the linked list
link *list1 = NULL;

void insertEnd(int x) {
    link *current = list1;
    while (current->next != NULL) {
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = x;
    new->next = NULL;
    current->next = new; // Use current to append the new node
}

void insertStart(int x) {
    link *new = (link *)malloc(sizeof(link));
    new->val = x;
    new->next = list1;
    list1 = new; // Update the head of the list
}

void deleteEnd(){
    link *current = list1;
    link *previous = current;
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
}

void deleteStart(){
    list1 = list1->next;
}

void display() {
    link *current = list1;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

void insert(int x, int loc){
    link *current = list1;
    link *previous = current;
    while(current->val!=loc){
        previous = current;
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = x;
    new->next = current;
    previous->next = new;
}

void delete(int loc){
    link *current = list1;
    link *previous = current;
    while(current->val!=loc){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current); 
}

int main(void) {
    insertStart(5);
    insertEnd(6);
    display();
    insertStart(1);
    display();
    insert(0, 5);
    display();
    delete(0);
    display();
    deleteEnd();
    display();
    deleteStart();
    display();
    deleteEnd();
    // Don't forget to free the memory for the linked list when done
    while (list1 != NULL) {
        link *temp = list1;
        list1 = list1->next;
        free(temp);
    }

    return 0;
}

// Just use the proper functions to implement stack/queue