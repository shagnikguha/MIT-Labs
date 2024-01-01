// using header file 
// code uses a header node to keep track of first element. In reality, this does not use a header node
#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    int val;
    struct link *next;
} link;

link* createHead(int x){
    link *head = (link *)malloc(sizeof(link));
    head->val = x;
    head->next = head;
    return head;
}

void insertEnd(link *head, int x) {
    link *current = head->next;
    while(current->next!=head){
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = x;
    new->next = head;       // connecting last node to head  (can use head instead of current->next)
    current->next = new;    // updating current node->next value
}

void insertStart(link *head, int x) {
    link *current = head->next;
    link *new = (link *)malloc(sizeof(link));
    new->val = x;
    new->next = current;
    head->next = new;
}

void deleteEnd(link *head) {
    link *current = head->next;
    link *previous = current;

    // Handle the case when the list is empty
    if (current == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }

    while (current->next != head) {
        previous = current;
        current = current->next;
    }
    previous->next = head;     // can use head instead of current->next
    free(current);
}

void deleteStart(link *head) {
    if (head->next != NULL) {
        link *temp = head->next;
        head->next = temp->next;
        free(temp);
    }
}

void display(link *head) {
    link *current = head;
    do{
        printf("%d ", current->val);
        current = current->next;
    } while(current != head);
    printf("\n");
}


void insert(link *head, int ins, int x){
    link *current = head->next;
    while(current->val != ins){
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = x;
    new->next = current->next;
    current->next = new;
}

void delete(link *head, int val){ 
    link *current = head->next;
    link *previous = current;
    if(current->val == val){   // condition to use deleteFirst in case the element is first in list
        deleteStart(head);
        return;
    }
    while(current->val != val){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
}

void insertbf(link *head, int ins, int val){
    link *current = head->next;
    link *previous = NULL;
    if(current->val == ins){   // condition to use deleteFirst in case the element is first in list
        insertStart(head, val);
        return;
    }
    while(current->val!=ins){
        previous = current;
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    previous->next = new;
    new->next = current;
}

int main(void) {
    link *head = createHead(9);

    insertStart(head, 5);
    insertEnd(head, 6);
    display(head);
    insertStart(head, 1);
    display(head);
    deleteEnd(head);
    display(head);
    insert(head, 1, 2);
    display(head);
    delete(head, 1);
    display(head);
    insertbf(head, 5, 0);
    display(head);

    // Free memory when done
    free(head);

    return 0;
}


// Just use the proper functions to implement stack/queue