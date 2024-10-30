#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of nodes for the queue in BFS

// Definition of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for BFS
struct Queue {
    struct Node* items[MAX];
    int front;
    int rear;
};

// Function to create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if queue is empty
int isEmpty(struct Queue* queue) {
    return queue->rear == -1;
}

// Add an item to the queue
void enqueue(struct Queue* queue, struct Node* node) {
    if (queue->rear == MAX - 1) return; // Queue is full
    if (queue->front == -1) queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = node;
}

// Remove an item from the queue
struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    struct Node* item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

// BFS traversal (Level Order Traversal)
void bfs(struct Node* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    printf("BFS (Level Order Traversal): ");
    while (!isEmpty(queue)) {
        struct Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL) enqueue(queue, current->left);
        if (current->right != NULL) enqueue(queue, current->right);
    }
    printf("\n");
}

// DFS traversals
// Preorder Traversal (Root-Left-Right)
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal (Left-Root-Right)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder Traversal (Left-Right-Root)
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    // Creating a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("DFS Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("DFS Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("DFS Postorder Traversal: ");
    postorder(root);
    printf("\n");

    bfs(root);

    return 0;
}
