#include<stdio.h>
#include<stdlib.h>
#define size 10
typedef struct QUEUE *queue;
typedef struct NODE *node;

struct NODE
{
    int data;
    node lchild;
    node rchild;
}*root=NULL;

struct stack
{
    node *arr;
    int *array;
    int tos;
};

struct QUEUE
{
    int front;
    int rear;
    node *arr;
} q;

void initqueue(queue q)
{
    q->arr=(node *)malloc(size*sizeof(node));
    q->front=0;
    q->rear=0;
}

void enqueue(node elt,queue q)
{
    q->rear=(q->rear+1)%size;
    q->arr[q->rear]=elt;

}

node dequeue(queue q)
{
    q->front=(q->front+1)%size;
    return q->arr[q->front];

}

void push(node elt,struct stack *s)
{
    s->tos++;
    s->arr[s->tos]=elt;
}

node pop(struct stack *s)
{
    return s->arr[s->tos--];
}

void preorder()
{
    if(root==NULL)
    {
        printf("empty tree \n");
        return;
    }

    struct stack s;
    s.arr=(node *)malloc(size*sizeof(node));
    s.tos=-1;

    node ptr=root;
    printf("preorder traversal results in order \n");
    while(ptr!=NULL || s.tos!=-1 )
    {
        if(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            push(ptr,&s);
            ptr=ptr->lchild;
        }

        else
        {
            ptr=pop(&s);
            ptr=ptr->rchild;
        }
    }
    printf("\n");

}

/*void postorder()
{
    struct stack s;
    s.arr=(node *)malloc(sizeof(struct NODE));
    s.array=(int *)malloc(sizeof(int));
    s.tos=-1;

    node ptr=root;
    push(ptr,&s);
    s.array[s.tos]=1;

    printf("postorder traversal gives \n");
    while(s.tos!=-1){
        if(ptr!=NULL && s.array[s.tos]!=-1){
            push(ptr,&s);
            s.array[s.tos]=1;
            ptr=ptr->lchild;
        }

        else if(s.arr[s.tos]->rchild!=NULL){
            s.array[s.tos]=-1;
            ptr=s.arr[s.tos]->rchild;
        }

        else{
          ptr=pop(&s);
          printf("%d ",ptr->data);
        }
    }

}*/

void insert_node()
{
    char str[10];
    int isnull=0,data,i;
    printf("enter string for insertion \n");
    scanf("%s",str);
    node ptr; //pointer for dynamic node creation
    node prev=NULL;
    node curr=root;

    for( i=0; str[i]!='\0'; i++)
    {
        if(curr==NULL && str[i]!='\0')    // if current is null and string has still not ended,terminate loop
        {
            isnull=1;
            break;
        }
        if(str[i]=='l' || str[i]=='L')
        {
            prev=curr;
            curr=curr->lchild;
        }

        else if(str[i]=='r' || str[i]=='R')
        {
            prev=curr;
            curr=curr->rchild;
        }
    }
    i--;
    if(isnull==1)
    {
        printf("insertion not possible \n");
        return;
    }

    else if(str[i]=='l' || str[i]=='L')
    {
        printf("enter data for insertion: ");
        scanf("%d",&data);
        ptr=(node)malloc(sizeof(struct NODE));
        ptr->data=data;
        ptr->lchild=curr;
        ptr->rchild=NULL;
        prev->lchild=ptr;
    }

    else if(str[i]=='r' || str[i]=='R')
    {
        printf("enter data for insertion: ");
        scanf("%d",&data);
        ptr=(node)malloc(sizeof(struct NODE));
        ptr->data=data;
        ptr->rchild=curr;
        ptr->lchild=NULL;
        prev->rchild=ptr;
    }

}

void levelorder()
{
    if(root==NULL)
    {
        printf("empty tree \n");
        return;
    }

    struct QUEUE q;
    initqueue(&q);
    node ptr;
    enqueue(root,&q);
    printf("level order traversal gives \n");

    while(q.front!=q.rear)
    {
        ptr=dequeue(&q);  //dequeue address and print data
        printf("%d ",ptr->data);

        if(ptr->lchild)  //if left child exists, enqueue its address
            enqueue(ptr->lchild,&q);

        if(ptr->rchild)   //if right child exists ,enqueue its address
            enqueue(ptr->rchild,&q);
    }
    printf("\n");
}


void create_binary_search_tree()
{
    int data;

    while(1)
    {
        node head=root;
        node tail=NULL;
        printf("Enter data to be inserted in bst(-1 to end): ");
        scanf("%d",&data);
        if(data==-1)  //if data is -1 ,end the process
            break;

        if(root==NULL)   //create root
        {
            node t=(node)malloc(sizeof(struct NODE));
            t->data=data;
            t->lchild=NULL;
            t->rchild=NULL;
            root=t;
        }

        else
        {
            while(head!=NULL)     // search for position to insert
            {
                if(data<head->data)
                {
                    tail=head;
                    head=head->lchild;
                }

                else
                {
                    tail=head;
                    head=head->rchild;
                }
            }
            if(data<tail->data)                      //insert at correct position
            {
                node t=(node)malloc(sizeof(struct NODE));
                t->data=data;
                t->lchild=NULL;
                t->rchild=NULL;
                tail->lchild=t;
            }

            else if(data>tail->data)
            {
                node t=(node)malloc(sizeof(struct NODE));
                t->data=data;
                t->lchild=NULL;
                t->rchild=NULL;
                tail->rchild=t;
            }

        }
    }

}

node create_tree()
{
    int data;
    struct QUEUE q;
    initqueue(&q);
    printf("enter data of root node \n");
    scanf("%d",&data);
    root=(node)malloc(sizeof(struct NODE));  //create root node
    root->data=data;
    root->lchild=NULL;
    root->rchild=NULL;
    enqueue(root,&q);    //enqueue root address

    node ptr2;
    printf("enter -1 to not create a node \n");

    while(q.rear!=q.front)     //until queue is empty,continue
    {
        node ptr=dequeue(&q);  //dequeue address from stack

        printf("enter data of %d lchild : ",ptr->data);
        scanf("%d",&data);
        if(data!=-1)   //create left child and enqueue its address in queue
        {
            ptr2=(node)malloc(sizeof(struct NODE));
            ptr2->data=data;
            ptr2->lchild=NULL;
            ptr2->rchild=NULL;
            ptr->lchild=ptr2;
            enqueue(ptr2,&q);
        }

        printf("enter data of %d rchild : ",ptr->data);
        scanf("%d",&data);
        if(data!=-1)     // create rchild and enqueue its address in stack
        {
            ptr2=(node)malloc(sizeof(struct NODE));
            ptr2->data=data;
            ptr2->lchild=NULL;
            ptr2->rchild=NULL;
            ptr->rchild=ptr2;
            enqueue(ptr2,&q);
        }

    }
    return root;

}

int main()
{
    int finish=0;
    // create_binary_search_tree();
    root=create_tree();
    // printf("no of nodes are %d \n",count_nodes(root));
    preorder();
    levelorder();
    while(finish!=1)
    {
        insert_node();
        preorder();
        printf("enter 1 to exit ");
        scanf("%d",&finish);
    }
    //postorder();
}



