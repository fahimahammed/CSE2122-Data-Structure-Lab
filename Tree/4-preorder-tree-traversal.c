#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

struct node* insertLeft(struct node* root, int value)
{
    root->left = createNode(value);
    return root->left;
};

struct node* insertRight(struct node* root, int value)
{
    root->right = createNode(value);
    return root->left;
};

void preorderTraversal(struct node* root)
{
    if(root == NULL){
        return;
    }
    printf(" %d ->", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    struct node* root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);

    insertLeft(root->left, 4);
    insertRight(root->left, 5);

    insertLeft(root->right, 6);
    insertRight(root->right, 7);

    printf("\nInorder Traversal: ");
    preorderTraversal(root);

    return 0;
}
