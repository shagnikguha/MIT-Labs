#include <stdio.h>
#include <stdlib.h>

typedef struct link{
    int val;
    struct link *next;
} link;

link* createH(){
    link *head =(link *)malloc(sizeof(link));
    head->next= NULL;
    return head;
}

void insertS(link *head, int val){
    link *current = head->next;
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->next = current;
    head->next = new;
}

void insertB(link *head, int val){
    link *current = head->next;
    while(current->next != NULL){
        current = current->next;
    }
    link *new = (link *)malloc(sizeof(link));
    new->val = val;
    new->next = current->next;
    current->next = new;
}

void deleteS(link *head){
    link *current = head->next;
    head->next = current->next;
    free(current);
}

void deleteB(link *head){
    link *current = head->next;
    link *previous = NULL;
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
}

void display(link *head){
    link *current = head->next;
    while(current->next != NULL){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("%d ", current->val);
    printf("\n");
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

void bubbleSort(link *start)  
{  
    int swapped, i;  
    link *ptr1;  
    link *lptr = NULL;  
  
    /* Checking for empty list */
    if (start == NULL)  
        return;  
  
    do
    {  
        swapped = 0;  
        ptr1 = start;  
  
        while (ptr1->next != lptr)  
        {  
            if (ptr1->val > ptr1->next->val)  
            {  
                swap(ptr1, ptr1->next);  
                swapped = 1;  
            }  
            ptr1 = ptr1->next;  
        }  
        lptr = ptr1;  
    }  
    while (swapped);  
}  
  
/* function to swap val of two links a and b*/
void swap(link *a, link *b)  
{  
    int temp = a->val;  
    a->val = b->val;  
    b->val = temp;  
}  

void delete(link *head, int del){
    link *current = head->next;
    link *previous = NULL;
    if(head->val == del){
        deleteS(head);
    }
    while(current->val != del){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
}

int main(void){
    link *head = createH();
    insertS(head, 1);
    insertB(head, 2);
    insertB(head, 3);
    insertS(head, 4);
    display(head);
    delete(head, 2);
    insert(head, 1, 5);
    display(head);
    bubbleSort(head);
    display(head);
}