// using header file 
// this code uses header file properly

#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    int val;
    struct link *next;
} link;

link* createLink(int val){
    link* new = (link*)malloc(sizeof(link));
    new->val = val;
    new->next = new;
    return new;
}

void insertStart(link *head, int val){
    link* current = head->next;
    link* new = (link *)malloc(sizeof(link));
    new->val = val;
    new->next = current; 
    while(current->next!=head->next){
        current = current->next;
    }
    current->next = new;
    head->next = new;
}

void insertEnd(link *head, int val){
    link *current = head->next;
    while(current->next!=head->next){
        current = current->next;
    }
    link* new =(link *)malloc(sizeof(link));
    new->val = val;
    new->next = current->next;
    current->next = new;
}

void deleteStart(link *head){
    link *current = head->next;
    link *temp = current;
    while(current->next!=head->next){
        current = current->next;
    }
    head->next = temp->next;
    current->next = head->next;
}

void deleteEnd(link *head){
    link *current = head->next;
    link *prev = NULL;
    while(current->next!=head->next){
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
}

void insertBfr(link *head, int ins, int val){
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
    prev->next = new;
    new->next = current;
}

void insert(link *head, int ins, int val){
    link *current = head->next;
    while(current->val != ins){
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->next = current->next;
    current->next = new;
}

void delete(link *head, int val){
    link *current = head->next;
    link *prev = NULL;
    if(current->val == val){
        deleteStart(head);
        return;
    }
    while(current->val != val){
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
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
    insertEnd(head, 0);
    display(head);
    insertBfr(head, 1, 6);
    insert(head, 0, 7);
    display(head);
    deleteStart(head);
    deleteEnd(head);
    delete(head, 1);
    display(head);    
    //printf("%d ", head->next->next->next->val);
    //printf("%d ", head->next->next->next->val);

}