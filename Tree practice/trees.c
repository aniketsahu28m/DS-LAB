#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

struct node* createNode(int data){
    struct node* n;
    n = (struct node* )malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preOrder( struct node *root){
    if(root!= NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder( struct node *root){
    if(root!= NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder( struct node *root){
    if(root!= NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if (prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node *search(struct node *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if (key<root->data)
    {
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
    
}

struct node *insert(struct node *root, int data){
    if(root==NULL){
        return createNode(data);
    }

    if (data < root->data){
        root->left=insert(root->left,data);
    }
    else if (data > root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

struct node *inOrderPre( struct node *root){
    root=root->left;
    while (root->right != NULL){
        root=root->right;
    }
    return root;
}


struct node *deleteNode(struct node*root,int value){
    struct node *iPre;

    if(root==NULL){
        return NULL;
    }

    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }

    if(value < root->data){
        root->left=deleteNode(root->left,value);
    }
    else if( value > root->data){
        root->right=deleteNode(root->right,value);
    }

    else{
        iPre = inOrderPre(root);
        root->data=iPre->data;
        root->left=deleteNode(root->left,iPre->data);
    }
    return root;
}

struct node* findParent(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return NULL;  // No parent if root is NULL or the node is the root itself
    }
    if ((root->left != NULL && root->left->data == key) ||
        (root->right != NULL && root->right->data == key)) {
        return root;  // Parent found
    }

    if (key < root->data) {
        return findParent(root->left, key);
    } else {
        return findParent(root->right, key);
    }
}

bool printAncestors(struct node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }

    // If key is found in left or right subtree, print the current node
    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return true;
    }

    return false;
}

int countLeafNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int findDepth(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}




int main(){
    struct node *p = createNode(4);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(5);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(3);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    printf("\n");
    printf("%d ",isBST(p));

    struct node* n = search(p,0);
    if(n!=NULL){
        printf("FOUND: %d ", n->data);
    }
    else{
        printf("ELEMENT NOT FOUND");
    }

    insert(p,9);
    insert(p,7);
    insert(p,8);
    insert(p,11);
    printf("\n");
    inOrder(p);

    deleteNode(p,9);
    deleteNode(p,4);
    printf("\n");
    inOrder(p);
    
    // Find the parent of node with value 3
    struct node* parent = findParent(p, 1);
    if (parent != NULL) {
        printf("Parent of 1: %d\n", parent->data);
    } else {
        printf("Parent not found or node is root.\n");
    }

    // Print ancestors of node with value 3
    printf("Ancestors of 1: ");
    if (!printAncestors(p, 1)) {
        printf("No ancestors found.");
    }
    printf("\n");

    // Count leaf nodes
    printf("Total leaf nodes: %d\n", countLeafNodes(p));

    // Find depth of the tree
    printf("Depth of the tree: %d\n", findDepth(p));


    return 0;
}
