
/*                          

Question :Write a C-program to convert infix expression to its equivalent postfix expression.
Name : Mahesh Ramdas Dubal

---------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include"validations.h"

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char elem) 
{
	stack[++top] = elem;
}

char pop()
{
	return(stack[top--]);
}

int precedence(char elem)  /* To check operator precedence */
{ 
	switch(elem)
	{
		case '+':
		case '-':	return 1;
		case '*':
		case '/':	return 2;
		case '^':	return 3;
		default :	return 0;
	}
}

void infixToPostfix(char infix[50],char postfix[50]) 
{
	int i = 0,k = 0;
	char ch,elem;
	push('#');

	while( (ch=infix[i]) != '\0')
	{
		if( ch == '(') 
		{
			push(ch);
		} 
		else if(isalnum(ch)) 
		{
			postfix[k++] = ch;
		} 
		else if( ch == ')') 
		{
			while(stack[top] != '(') 
			{
				postfix[k++] = pop();
			}
			elem = pop();    //for removing '(' and ')'
		} 
		else if(is_Operator(ch) == 1) /* Operator */
		{ 
			while(precedence(stack[top]) >= precedence(ch) ) 
			{
				postfix[k++] = pop();
			}
			push(ch);
		}
		i++;
	}
	while(stack[top] != '#') 
	{   
		postfix[k++] = pop();  /* Pop from stack till empty */
	}
	postfix[k]='\0';          /* Make prfx as valid string */

}

int main()
{
	char infix[50],postfix[50];
	int i = 0;

	printf("\nEnter the Infix Expression : ");
	gets(infix);


	while(CheckExp(infix) == 0 || strlen(infix) == 0) 
	{
		printf("Enter Valid Expression !!\n\n");

		printf("\nEnter  the Infix Expression : ");
		gets(infix);

		if(CheckExp(infix) == 1 && strlen(infix) != 0)
		{
			infixToPostfix(infix,postfix);
			printf("\n\nGiven Infix Expn: %s\n\n  Postfix Expn: %s\n",infix,postfix);

			return 0;
		}

	}

	infixToPostfix(infix,postfix);
	printf("\n\nGiven Infix Expression: %s\n\n  Postfix Expression: %s\n",infix,postfix);

	return 0;
}

