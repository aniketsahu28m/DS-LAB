#include <stdio.h>
#include <stdlib.h>

// Define a TreeNode structure and use a typedef for convenience
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

TreeNode* findMinNode(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else//root is found
    {
        if (root->left == NULL)
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = findMinNode(root->right); // as we can replace a data with its inorder predecessor,which will be the min in right subtree
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);// coz temp data double ho gaya
    }
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
TreeNode *SearchBST(int key,TreeNode *croot){
    while(croot!=NULL && croot->data!=key){

            croot=(key < croot->data)? croot->left:croot->right;
    }
    return croot;
}

int main() {
    TreeNode* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a value\n");
        printf("2. Delete a value\n");
        printf("3. Search a value\n");
        printf("4. Display tree(inorder traversal)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &value);
                TreeNode *temp=SearchBST(value,root);
                (temp!=NULL)? printf("Key found!"):printf("Key not found");
                break;
            case 4:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                // Clean up and exit
                free(root); // Release memory
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
