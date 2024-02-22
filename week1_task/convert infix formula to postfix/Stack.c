#include "Stack.h"



void InitialStack(Stack *ps)
{
	ps->top = 0;
}

void Push(StackEntry e, Stack *ps)
{
	ps->entry[ps->top++] = e;
}

int StackFull(Stack *ps)
{
	return ps->top == MAXSTACK;
}

void Pop(StackEntry *pe, Stack *ps)
{
	*pe = ps->entry[--ps->top];
}

int StackEmpty(Stack *ps)
{
	return !ps->top;
}

void StackTop(StackEntry *pe, Stack *ps)
{
	*pe  = ps->entry[ps->top-1];
}

int StackSize(Stack *ps)
{
	return ps->top;
}

void ClearStack(Stack *ps)
{
	ps->top = 0;
}

void TreverseStack(Stack *ps, void (*pf)(StackEntry))
{
	int i;
	for(i = ps->top; i > 0; i--)
		(*pf)(ps->entry[i-1]);
}






