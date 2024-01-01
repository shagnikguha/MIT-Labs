#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *lchild;
    struct node *rchild;
} node;

node* createBinary(int val){
    int x;
    if(val!=-1){
        node *temp = (node *)malloc(sizeof(temp));
        temp->val = val;

        printf("Enter lchild of %d: ", val);
        scanf("%d", &x);
        temp->lchild = createBinary(x);

        printf("Enter rchild of %d: ", val);
        scanf("%d", &x);
        temp->rchild = createBinary(x);

        return temp;
    }    
    return NULL;
}

node* copyTree(node *child){
    if(child == NULL)
        return NULL;
    node *newChild = (node *)malloc(sizeof(node));
    newChild->val = child->val;
    newChild->lchild = copyTree(child->lchild);
    newChild->rchild = copyTree(child->rchild);
    return newChild;
}

node* mergeBinary(node *t1, node *t2){
    if(t1 == NULL)
        return NULL;
    if(t2 == NULL)
        return NULL;
    int Tval = t1->val + t2->val;
    node *child = (node *)malloc(sizeof(node));
    child->val = Tval;
    child->lchild = mergeBinary(t1->lchild, t2->lchild);
    child->rchild = mergeBinary(t1->rchild, t2->rchild);
    return child;
}

int areTreesEqual(node *t1, node *t2) {
    // If both trees are empty, they are equal
    if (t1 == NULL && t2 == NULL) {
        return 1;  // true
    }
    
    // If one tree is empty and the other is not, they are not equal
    if (t1 == NULL || t2 == NULL) {
        return 0;  // false
    }

    // Check if the values are equal at the current node
    if (t1->val != t2->val) {
        return 0;  // false
    }

    // Recursively check the left and right subtrees
    return areTreesEqual(t1->lchild, t2->lchild) && areTreesEqual(t1->rchild, t2->rchild);
}

void inorder(node* root){
    if(root==NULL)
        return;
    inorder(root->lchild);
    printf("%d,", root->val);
    inorder(root->rchild);
}

void preorder(node* root){
    if(root==NULL)
        return;
    printf("%d,", root->val);
    preorder(root->lchild);
    preorder(root->rchild);
}

void postorder(node* root){
    if(root==NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d,", root->val);
}


int count_leaf(node *root){
    static int c = 0;
    if(root!=NULL){
        if(root->lchild==NULL && root->rchild==NULL){
            c++;
        }
        count_leaf(root->lchild);
        count_leaf(root->rchild);
    }
    return c;
}

int main(void){
    int x;
    printf("Enter root node value: ");
    scanf("%d", &x);
    node *tree = createBinary(x);
    inorder(tree);
    printf("\n");
    /*
    preorder(tree);
    printf("\n");
    postorder(tree);
    printf("\n");
    */
    node *treeN = copyTree(tree);
    inorder(treeN);
    printf("\n");
    printf("%d\n", areTreesEqual(tree, treeN));
    int c = count_leaf(treeN);
    printf("%d", c);
    node *tree2 = createBinary(1);
    node *treeM = mergeBinary(tree, tree2);
    inorder(treeM);
    printf("\n");
}

 