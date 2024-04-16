#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    int balanceFactor; // New field for balance factor
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->balanceFactor = 0; // Initialize balance factor to 0
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the balance factor of a node
int calculateBalanceFactor(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return leftHeight - rightHeight;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    root->balanceFactor = calculateBalanceFactor(root); // Update balance factor
    return root;
}

// Function for inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d (BF: %d) ", root->data, root->balanceFactor); // Print balance factor
        inorder(root->right);
    }
}

// Function for preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d (BF: %d) ", root->data, root->balanceFactor); // Print balance factor
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d (BF: %d) ", root->data, root->balanceFactor); // Print balance factor
    }
}

// Function to get the height of a node
int getHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int main() {
    struct Node* root = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}