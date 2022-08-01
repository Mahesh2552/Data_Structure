
/*                          

Question :Write a C-program to convert infix expression to its equivalent prefix expression.
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
    stack[++top]=elem;
}

char pop()
{                      
    return(stack[top--]);
}


int pr(char elem) //to check precedence
{                 
    switch(elem)
    {
	    case '#': return 0;
	    case '+':
	    case '-': return 1;
	    case '*':
	    case '/': return 2;
        case '^': return 3;
    }
	
	return -1;
}

void infixToPrefix(char infx[50],char prfx[50])
{
    int i = 0,k = 0;
    char ch,elem;
    
    push('#');
    strrev(infx);

    while( (ch=infx[i++]) != '\0')    
	{
		if( ch == ')')
		{
			push(ch);
		}
		else
		{
			if(isalnum(ch))
			{
				prfx[k++]=ch;
			} 
			else
			{
				if( ch == '(')
				{
					while( stack[top] != ')')
					{
						prfx[k++] = pop();
					} 
					elem=pop(); /* Remove ) */
				}
				else if(is_Operator(ch) == 1)
				{       
					while( pr(stack[top]) >= pr(ch) )
					{
						prfx[k++] = pop();
					}
					push(ch);
				}
			}   
		}
        
    }
    
    while( stack[top] != '#')     /* Pop from stack till stack is empty */
    {
        prfx[k++] = pop();
    }   
    prfx[k] = '\0';          /* Make prfx as valid string */

}

int main() /* Main Program */
{                         
    char infx[50],prfx[50];

    printf("\nEnter the Infix Expression : \n");
    gets(infx);
	
	
	while(checkExp(infx) == 0)
	{
		printf("\nEnter Valid Expression !!\n");
		
		printf("\nEnter  the Infix Expression : \n");
		gets(infx);
		
		if(checkExp(infx) == 1)
		{
			infixToPrefix(infx,prfx);
			
			strrev(prfx);
			strrev(infx);
			
			printf("\n\nGiven Infix Expression: %s\n\n  Prefix Expression: %s\n",infx,prfx);
			
			return 0;
		}
		
	}
	
	infixToPrefix(infx,prfx);
	
	strrev(prfx);
    strrev(infx);

    printf("\n\nGiven Infix Expression: %s\n\n  Prefix Expression: %s\n",infx,prfx);
    return 0;
}

