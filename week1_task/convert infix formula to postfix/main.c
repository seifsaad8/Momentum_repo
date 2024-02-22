#include <stdio.h>
#include "Stack.h"

void Display(StackEntry);
void InfixToPostfix(char infix[], char postfix[]);
int IsDigit(char);
int Precedent(char);

int main()
{
	char infix[100],postfix[100];
	printf("please make Sure u Read this information \n"
			"u can use only those operators  ( ) , * , / , +, -, ^(this is the power sign) \n"
			"make sure u enter a single num between zero and nine.\n");
	fflush(stdin);fflush(stdout);
	printf("Enter the infix expression : ");
	fflush(stdin);fflush(stdout);
	scanf("%s", infix);
	InfixToPostfix(infix, postfix);
	printf("The postfix expression is : %s", postfix);

    return 0;
}

void InfixToPostfix(char infix[], char postfix[])
{
	int i, j;
	char e, c;
	Stack s;
	InitialStack(&s);

	for(i = 0, j = 0; (c = infix[i]) != '\0'; i++)
	{
		if(IsDigit(c))
		{
			postfix[j++] = c;
		}
		else if (c == '(')
		{
			Push(c, &s);
		}
		else if (c == ')')
		{
			while (!StackEmpty(&s) && (StackTop(&e, &s), e != '('))
			{
				Pop(&e, &s);
				postfix[j++] = e;
			}
			Pop(&e, &s);
		}
		else
		{
			if(!StackEmpty(&s))
			{
				StackTop(&e, &s);
				while(!StackEmpty(&s) && Precedent(e) >= Precedent(c) && e != '(')
				{
					Pop(&e, &s);
					postfix[j++] = e;
					if(!StackEmpty(&s))
					{
						StackTop(&e, &s);
					}
				}
			}
		    Push(c, &s);
		}
	}
	while(!StackEmpty(&s))
	{
		Pop(&e, &s);
		postfix[j++] = e;
	}
	postfix[j] = '\0';
}


int IsDigit(char c)
{
	return (c >= '0' && c <= '9');
}

int Precedent(char e)
{
	if(e == '(' || e == ')')
		return 4;
	if(e == '^')
		return 3;
	if(e == '*' || e == '/')
		return 2;
	if(e == '+' || e == '-')
		return 1;
	return 0;
}


void Display(StackEntry e)
{
	printf("e is : %c\n", e);

}

