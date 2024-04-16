#include <stdio.h>
#include <stdlib.h>

// Structure for a node in AVL tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to get the height of a node
int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the balance factor of a node
int getBalanceFactor(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to update the height of a node
void updateHeight(struct Node* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to perform a right rotation
struct Node* rotateRight(struct Node* node) {
    struct Node* newRoot = node->left;
    struct Node* temp = newRoot->right;

    newRoot->right = node;
    node->left = temp;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

// Function to perform a left rotation
struct Node* rotateLeft(struct Node* node) {
    struct Node* newRoot = node->right;
    struct Node* temp = newRoot->left;

    newRoot->left = node;
    node->right = temp;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

// Function to insert a node into the AVL tree
struct Node* insertNode(struct Node* root, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    // If the tree is empty, return the new node
    if (root == NULL)
        return newNode;

    // Perform iterative insertion
    struct Node* curr = root;
    struct Node* parent = NULL;
    while (curr != NULL) {
        parent = curr;
        if (data < curr->data)
            curr = curr->left;
        else if (data > curr->data)
            curr = curr->right;
        else {
            // Duplicate values are not allowed in AVL tree
            free(newNode);
            return root;
        }
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    // Update the height of the parent node
    updateHeight(parent);

    // Perform AVL tree balancing
    int balanceFactor = getBalanceFactor(parent);
    if (balanceFactor > 1) {
        if (data < parent->left->data)
            return rotateRight(parent);
        else {
            parent->left = rotateLeft(parent->left);
            return rotateRight(parent);
        }
    }
    if (balanceFactor < -1) {
        if (data > parent->right->data)
            return rotateLeft(parent);
        else {
            parent->right = rotateRight(parent->right);
            return rotateLeft(parent);
        }
    }

    return root;
}

// Function to print the AVL tree in inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the memory allocated for the AVL tree
void freeAVLTree(struct Node* root) {
    if (root != NULL) {
        freeAVLTree(root->left);
        freeAVLTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int numNodes, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("Inorder traversal of the AVL tree: ");
    inorderTraversal(root);
    printf("\n");

    freeAVLTree(root);

    return 0;
}

/*
sample input
Enter the number of nodes: 7
Enter the values of the nodes:
20
10
30
5
15
25
35
*/