#include <stdio.h>
#include <stdlib.h>

struct Node {
    int nodeInfo;
    struct Node* left;
    struct Node* right;
}Node;

struct Node* insert(struct Node* node, int nodeInfo) {
    if (node == NULL) {
        struct Node* newVar = (struct Node*)malloc(sizeof(struct Node));
        newVar->nodeInfo = nodeInfo;newVar->left = NULL;newVar->right = NULL;
        printf("inserted\n");
        return newVar;
    }
    if (nodeInfo < node->nodeInfo)
    {
        node->left = insert(node->left, nodeInfo);
    }
        
    else if (nodeInfo > node->nodeInfo)
    {
        node->right = insert(node->right, nodeInfo);
    }
        
    else
    {
        printf("not inserted\n");
        return node;
    }
    printf("inserted\n");
    return node;
}

struct Node* parse(struct Node* node, int nodeInfo) {
    if (node == NULL) {
        printf("absent\n");
        return NULL;
    }
    if (node->nodeInfo == nodeInfo) {
        printf("present\n");
        return node;
    }
    if (nodeInfo < node->nodeInfo)
        return parse(node->left, nodeInfo);
    return parse(node->right, nodeInfo);
}

struct Node* lowestNode(struct Node* node) {
    struct Node* actNode = node;
    while (actNode->left != NULL)
        actNode = actNode->left;
    return actNode;
}

struct Node* deleteNode(struct Node* root, int nodeInfo) {
    if (root == NULL)
        return root;
    if (nodeInfo < root->nodeInfo)
        root->left = deleteNode(root->left, nodeInfo);
    else if (nodeInfo > root->nodeInfo)
        root->right = deleteNode(root->right, nodeInfo);
    else {
        if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node* temp = root->left; free(root);
            return temp;
        }
        struct Node* temp = lowestNode(root->right);
        root->nodeInfo = temp->nodeInfo;
        root->right = deleteNode(root->right, temp->nodeInfo);
    }
    return root;
}

void printTree(struct Node* root) {
    if (root != NULL) {
        // left sub-tree center right sub-tree
        printf("(");
        printTree(root->left);
        printf("%d", root->nodeInfo);
        printTree(root->right);
        printf(")");
    } else {
        printf("");
    }
}

int main() {

    char input[3]; struct Node* root = NULL;
    while (1) {
        int chkVal;
        if (scanf(" %2s %d", input, &chkVal) == 2) {
            if (root == NULL) {
                root = insert(root, chkVal);
            }
            else {
                if (input[0] == 'i') {
                    insert(root, chkVal);
                } else if (input[0] == 'p') {
                    printTree(root);
                } else if (input[0] == 's') {
                    parse(root, chkVal);
                } else if (input[0] == 'd') {
                    deleteNode(root, chkVal);
                }
                else {
                break;
            }
            }
        }
        printTree(root);
    }
    return 0;
}