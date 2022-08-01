
/*                            

Question : Write a c program to Reverse a string using stack using stack.
Name : Mahesh Ramdas Dubal

---------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"validations.h"

#define SIZE 100

int top = -1;
char stack[SIZE];

void push(char ch)
{
	if(top == SIZE-1)
	{
		printf("Stack is overflow\n");
	}
	else
	{
		stack[++top] = ch;
	}
}

void pop()
{
	printf("%c",stack[top--]); 
}

void RevStr(char str[] )
{
	
	int length = 0,i = 0;

	length = strlen(str);

	for(i = 0;i < length; i++)
	{
		push(str[i]);
	}

	for(i = 0;i < length; i++)
	{
		pop(str[i]);
	}
}
int main()
{
	char str[SIZE];

	int invalid = 1;
	
	while(invalid == 1)
	{
		printf("Enter your string : ");
		gets(str);
		
		if(strlen(str) != 0 && isSpace(str) == 1)
		{
			printf("Reverse String : ");
			RevStr(str);	
			invalid = 0;
		}
		else
		{
			printf("Enter a valid string!!!\n");
			invalid = 1;
		}
	}
	
	return 0;
}
