#ifndef STACK_H_
#define STACK_H_



#define MAXSTACK 100
#define StackEntry char

typedef struct stack
{
	int top;
	StackEntry entry[MAXSTACK];
}Stack;


void InitialStack(Stack*);
void Push(StackEntry, Stack*);
int StackFull(Stack*);
void Pop(StackEntry*, Stack*);
int StackEmpty(Stack*);
void StackTop(StackEntry*, Stack*);
int StackSize(Stack*);
void ClearStack(Stack*);
void TreverseStack(Stack*, void (*)(StackEntry));

#endif
