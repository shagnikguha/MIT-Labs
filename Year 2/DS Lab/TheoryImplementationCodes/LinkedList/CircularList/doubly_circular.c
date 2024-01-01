#include <stdio.h>
#include <stdlib.h>

typedef struct link{
    int val;
    struct link *next;
    struct link *prev;
} link;

link* createLink(int val){
    link* head = (link *)malloc(sizeof(link));
    head->val = val;
    head->next = head->prev = head;
    return head;
}

void insertStart(link *head, int val){
    link *current = head->next;
    link *temp = current;
    while(current->next != head->next){
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->next = temp;
    new->prev = current;
    current->next = new;
    temp->prev = new;
    head->next = new;
}

void insertEnd(link *head, int val){
    link *current = head->next;
    while(current->next != head->next){
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->prev = current;
    current->next = new;
    new->next = head->next;
    head->next->prev = new;
}

void deleteStart(link *head){
    link *current = head->next;
    link *nextL = current->next;
    head->next = nextL;
    nextL->prev = current->prev;
    current->prev->next = nextL;
}

void deleteEnd(link *head){
    link *current = head->next;
    link *previous = NULL;
    while(current->next != head->next){ 
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    head->next->prev = previous;
}

void delete(link *head, int val){
    link *current = head->next;
    link *previous = NULL;
    if(current->val==val){
        deleteStart(head);
        return;
    }
    while(current->val != val){ 
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    current->next->prev = previous;
}

void insert(link *head, int ins, int val){
    link *current = head->next;
    while(current->val != ins){ 
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->next = current->next;
    new->prev = current;
    current->next->prev = new;
    current->next = new;
}

void insertbf(link *head, int ins, int val){
    link *current = head->next;
    link *prev = NULL;
    if(current->val == ins){
        insertStart(head, val);
        return;
    }
    while(current->val != ins){ 
        prev = current;
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->next = current;
    new->prev = prev;
    current->prev = new;
    prev->next = new;
}

void display(link *head){
    link* first = head->next;
    do{
        printf("%d ", first->val);
        first = first->next;
    } while(first != head->next);
    printf("\n");
}


int main(void){
    link* head = (link *)malloc(sizeof(link)); 
    head->next = createLink(1); 
    insertStart(head, 2);
    insertStart(head, 5);
    display(head);
    insertEnd(head, 0);
    insertEnd(head, 9);
    display(head);
    deleteStart(head);
    display(head);
    deleteEnd(head);
    display(head);
    delete(head, 1);
    display(head);
    insert(head,2,3);
    display(head);
    insertbf(head, 3, 1);
    display(head);
}