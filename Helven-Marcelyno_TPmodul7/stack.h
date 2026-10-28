#ifndef STACK_H
#define STACK_H

typedef char infotype;

struct stack {
    infotype info[15];
    int Top;
};

#define Top(S) (S).Top
#define info(S) (S).info

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype x);
infotype pop(stack &S);
void printInfo(stack S);

#endif
