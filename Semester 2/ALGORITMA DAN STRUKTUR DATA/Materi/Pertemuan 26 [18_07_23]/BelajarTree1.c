
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int value){
    Node *newNode = malloc(sizeof(Node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertLeft(Node *root, int value){
    root->left = createNode(value);
    return root->left;
}

Node *insertRight(Node *root, int value){
    root->right = createNode(value);
    return root->right;
}

void inOrderTraversal(Node *root){
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d -> ", root->item);
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root){
    if(root == NULL) return;
    printf("%d -> ", root->item);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root){
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d -> ", root->item);
}

int main(){
    Node *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);

    insertLeft(root->left, 4);
    insertRight(root->left, 5);

    printf("\nIn-Order Traversal: ");
    inOrderTraversal(root);

    printf("\nPre-Order Traversal: ");
    preOrderTraversal(root);

    printf("\nPost-Order Traversal: ");
    postOrderTraversal(root);

}
