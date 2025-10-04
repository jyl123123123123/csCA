#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* create(int value)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    if(!newNode)
    {
        exit(1);
    }
    
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(Node** head, int value)
{
    Node* newNode = create(value);
    newNode->next = *head;
    *head = newNode;
}

void insertInIncreasingNumericOrder(Node** head, int value) 
{
    Node* newNode = create(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if ((*head)->data == value) {
        free(newNode);
        return;
    }

    if ((*head)->data > value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;

    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }

    if (temp->next != NULL && temp->next->data == value) {
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}



void insertAtTail(Node** head, int value)
{
    Node* newNode = create(value);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteValue(Node** head, int value)
{
    Node* temp = *head;
    Node* prev = NULL;

    while(temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        return;
    }
    if(prev == NULL)
    {
        *head = temp->next;
    }else{
        prev->next = temp->next;
    }
    free(temp);
}

int count(Node* head)
{
    int count = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        count+=1;
        temp = temp->next;
    }
    return count;
}

void printList(Node* head)
{
    Node* temp = head;
    printf("%d :", count(head));
    if (temp != NULL) {
        printf("%s", " ");
    }
    while(temp != NULL)
    {
        printf("%d", temp->data);
        if ((temp->next != NULL)) {
            printf("%s", " ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


