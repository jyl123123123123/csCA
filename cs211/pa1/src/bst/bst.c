#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        printf("inserted\n");
        return newNode;
    }
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else {
        printf("not inserted\n");
    }
    return node;
}


struct Node* search(struct Node* node, int data) {
    if (node == NULL) {
        printf("absent\n");
        return NULL;
    }
    if (node->data == data) {
        printf("present\n");
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
    if (root == NULL) {
        printf("absent\n");
        return NULL;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = delete(root->right, data);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            printf("deleted\n");
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            printf("deleted\n");
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
    }
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char input;
    struct Node* root = NULL;

    while (scanf(" %c", &input) != EOF) {
        int num;

        if (input == 'i') {
            if (scanf("%d", &num) == EOF) break;
            root = insert(root, num);
        }
        else if (input == 's') {
            if (scanf("%d", &num) == EOF) break;
            search(root, num);
        }
        else if (input == 'd') {
            if (scanf("%d", &num) == EOF) break;
            root = delete(root, num);
        }
        else if (input == 'p') {
            printTree(root);
            printf("\n");
        }
    }

    freeTree(root);
    return 0;
}
