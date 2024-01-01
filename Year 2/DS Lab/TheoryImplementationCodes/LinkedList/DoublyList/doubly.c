#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    int val;
    struct link *prev;
    struct link *next;
} link;

void insertStart(link *head, int val) {
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->next = head->next;
    
    if (head->next != NULL) {
        head->next->prev = new;
    }

    head->next = new;
}

void insertEnd(link *head, int val) {
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->next = NULL;

    link *current = head->next;
    while (current->next != NULL) {
        current = current->next;
    }

    new->prev = current;
    current->next = new;
}

void deleteStart(link *head) {
    if (head->next == NULL) {
        return; // List is empty, so there is nothing to delete
    }

    link *current = head->next;
    head->next = current->next;
    if (current->next != NULL) {
        current->next->prev = head;
    }

    free(current);
}

void deleteEnd(link *head) {
    if (head->next == NULL) {
        return; // List is empty, so there is nothing to delete
    }

    link *current = head->next;
    link *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);
}

void display(link *head) {
    link *current = head->next;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }

    printf("\n");
}

 
// To insert before a value
void insertBfr(link *head, int ins, int val){
    link *current = head->next;
    link *previous = NULL;
    while(current->val != ins){
        previous = current;
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->prev = previous;
    new->next = current;
    if (previous != NULL) {
            previous->next = new;
    } else {
        // If 'previous' is NULL, it means 'current' is the head of the list
        head->next = new;
    }
    current->prev = new;
} 

void insert(link *head, int ins, int val){
    link *current = head->next;
    while(current->val != ins){
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->prev = current;
    new->next = current->next;
    current->next = new;
}

void delete(link *head, int val){
    link *current = head->next;
    link *previous = NULL;
    if(current->val == val){
        deleteStart(head);
        return;
    }
    while(current->val != val){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    if(current->next != NULL){
        current->next->prev = previous;
    }
    free(current);
}

int main() {
    // Create a head node for the doubly linked list
    link *head = (link *)malloc(sizeof(link));
    head->prev = NULL;
    head->next = NULL;
    head->val = 0; // Initialize head's data value

    // Insert elements at the beginning and end
    insertStart(head, 5);
    insertStart(head, 3);
    insertEnd(head, 8);

    // Display the list
    printf("Original List: ");
    display(head);

    // Delete elements from the beginning and end

    deleteStart(head);
    deleteEnd(head);
    insert(head, 5, 9);
    delete(head, 5);

    printf("Modified List: ");
    display(head);

    free(head);

    return 0;
}
