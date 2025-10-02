#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // the maximum of the stack

typedef struct
{
    char arr[MAX];
    int top;
}Stack;

static inline void init(Stack *s)
{
    s->top = -1;
}

static inline int isEmpty(Stack *s)
{
    return s->top == -1;
    //1 if true
    //0 if false
}

static inline int isFull(Stack *s){
    return s->top == MAX -1;//99
}

static inline void push(Stack *s, char value){
    if(isFull(s))
    {
        //printf("full!\n");
        return;
    }
    s->arr[++s->top] = value;
}

static inline char pop(Stack *s)
{
    if(isEmpty(s))
    {
        //printf("empty!\n");
        return -1;
    }
    return s->arr[s->top--];
}

static inline int peek(Stack *s)
{
    if(isEmpty(s))
    {
        //printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

#endif