#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        printf("Inserted\n");
        return newNode;
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
        
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
        
    else
    {
        printf("Not inserted\n");
        return node;
    }
    printf("Inserted\n");
    return node;
}

struct Node* search(struct Node* node, int data) {
    if (node == NULL) {
        printf("Absent\n");
        return NULL;
    }
    if (node->data == data) {
        printf("Present\n");
        return node;
    }
    if (data < node->data)
        return search(node->left, data);
    return search(node->right, data);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void printTree(struct Node* root) {
    if (root != NULL) {
        printf("(");
        printTree(root->left);
        printf("%d", root->data);
        printTree(root->right);
        printf(")");
    } else {
        printf("");
    }
}

int main() {

printf("%s\n", "Please state your input. 'i #' for insertion, 'd #' for deletion.");
    char input[3];
    struct Node* root = NULL;
    while (1) {
        int num;
        if (scanf(" %2s %d", input, &num) == 2) {
            if (root == NULL) {
                root = insert(root, num);
            }
            else {
                if (input[0] == 'i') {
                    insert(root, num);
                } else if (input[0] == 'd') {
                    delete(root, num);
                } else if (input[0] == 's') {
                    search(root, num);
                } else if (input[0] == 'p') {
                    printTree(root);
                }
                else {
                    printf("Invalid argument.\n");
                break;
            }
            }
        }
        printf("%s\n", "DEBUG: The current tree is: ");
        printTree(root);
    }
    return 0;
}