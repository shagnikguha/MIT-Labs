#include <stdio.h>
#include <stdlib.h>

#define size 10

typedef struct NODE *NODE;

struct NODE
{
    int data;
    NODE lchild;
    NODE rchild;
} *root = NULL;
struct NODE* create_binary_search_tree()
{
    int data;

    while (1)
    {
        NODE head = root;
        NODE tail = NULL;
        printf("Enter data to be inserted in bst -1 to end: ");
        scanf("%d", &data);
        if (data == -1) //if data is -1, end the process
            break;

        if (root == NULL) //create root
        {
            NODE t = (NODE)malloc(sizeof(struct NODE));
            t->data = data;
            t->lchild = NULL;
            t->rchild = NULL;
            root = t;
        }

        else
        {
            while (head != NULL) // search for position to insert
            {
                if (data < head->data)
                {
                    tail = head;
                    head = head->lchild;
                }

                else
                {
                    tail = head;
                    head = head->rchild;
                }
            }
            if (data < tail->data) //insert at correct position
            {
                NODE t = (NODE)malloc(sizeof(struct NODE));
                t->data = data;
                t->lchild = NULL;
                t->rchild = NULL;
                tail->lchild = t;
            }

            else if (data > tail->data)
            {
                NODE t = (NODE)malloc(sizeof(struct NODE));
                t->data = data;
                t->lchild = NULL;
                t->rchild = NULL;
                tail->rchild = t;
            }
        }
    }

    return root; 
}

struct NODE* deleteNODE(struct NODE* root, int k)
{
    if (root == NULL)
        return root;

    if (k < root->data) {
        root->lchild = deleteNODE(root->lchild, k);
    } else if (k > root->data) {
        root->rchild = deleteNODE(root->rchild, k);
    } else {
        if (root->lchild == NULL) {
            struct NODE* temp = root->rchild;
            free(root);
            return temp;
        } else if (root->rchild == NULL) {
            struct NODE* temp = root->lchild;
            free(root);
            return temp;
        }

        struct NODE* succParent = root;

        struct NODE* succ = root->rchild;
        while (succ->lchild != NULL) {
            succParent = succ;
            succ = succ->lchild;
        }

        if (succParent != root)
            succParent->lchild = succ->rchild;
        else
            succParent->rchild = succ->rchild;

        root->data = succ->data;

        free(succ);
    }

    return root;
}

struct NODE* insert(struct NODE* node, int data)
{
    if (node == NULL)
    {
        NODE t = (NODE)malloc(sizeof(struct NODE));
        t->data = data;
        t->lchild = NULL;
        t->rchild = NULL;
        return t;
    }

    if (data < node->data)
        node->lchild = insert(node->lchild, data);
    else if (data > node->data)
        node->rchild = insert(node->rchild, data);

    return node;
}

void inorder(struct NODE* root)
{
    if (root == NULL)
        return;

    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}

int main()
{
    root = create_binary_search_tree();
    printf("Inorder Traversal after creation:\n");
    inorder(root);

    int n;
    printf("\nEnter no to delete:\n");
    scanf("%d", &n);
    root = deleteNODE(root, n);
    printf("Inorder Traversal after deletion:\n");
    inorder(root);

    printf("\nEnter no to insert:\n");
    scanf("%d", &n);
    root = insert(root, n);
    printf("Inorder Traversal after insertion:\n");
    inorder(root);

    return 0;
}
