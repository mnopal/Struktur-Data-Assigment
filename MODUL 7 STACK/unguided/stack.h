#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX = 20;

typedef int infotype;
typedef struct {
    infotype info[MAX];
    int top;
} Stack;

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif // STACK_H_INCLUDED