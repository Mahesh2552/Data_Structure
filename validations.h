
#include<string.h>
#include<ctype.h>

int checkInteger(char s[])
{
	int len=strlen(s),flag=0,flag1 =0,i,flag2;  
	
	for(i=0;i<len;i++)
	{
		if(s[i] == ' ')
		{
			flag2 = 0;	
		}
	}
	for(i=0;i<len;i++)
	{
	    if(!(s[i]>='0' && s[i]<='9'))  
		{
			flag=0;
		}
		else
		{
			flag++;
		}
	}
	if(flag > 0)
	{
		if(( s[0]=='+') || ( s[0]=='-' ))
		{
			flag++;
		}
	}
	
	if(len == 0  || flag2 == 0)
	{
		return 0;
	}
	if(flag==len )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int is_Operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-'|| symbol =='%')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int checkExp(char infix[])
{
	int len = strlen(infix) , count = 0,i = 0;
	int flag = 0,flag1 = 0,flag2 = 0,flag3 = 0,flag4 = 0;
	
	if(isalnum(infix[0]))
	{
		flag2++;
	}
	else if(infix[0] == '(')
	{
		flag3++;
	}
	
	for( i = 1 ; i <= len; i++)
	{
		if(is_Operator(infix[i]) == 1)
		{
			flag1++;
		}
		
		else if( isalnum(infix[i]) )
		{
			flag2++;
		}
		
		else if(infix[i] == '(' )
		{
			flag3++;
		}
		else if(infix[i] == ')')
		{
			flag4++;
		}
		else if(infix[i] == 32)
		{
			return 0;
		}
	}
	
	flag = flag1+flag2+flag3+flag4;
	
	if((len == flag) && (flag1 == flag2-1 )&& (flag3 == flag4 ))
	{
		return 1;
	}
	
	else if(len == 0)
	{
		return 0;
	}
	else
	{
		return 0;
	}
}

int checkPosExp(char postfix[])
{
	int len = 0,flag = 0,i = 0,flag1 = 0;
	char ch;
	len = strlen(postfix);
	if(isdigit(postfix[0]))
	{
		flag++;
	}
	for(i = 1;i<=len;i++)
	{
		ch = postfix[i];
		if(isdigit(ch))
		{
			flag++;	
		}
		else if(is_Operator(ch) == 1)
		{
			flag1++;
		}
		else if(postfix[i] == 32)
		{
			return 0;
		}
	}
	if((flag + flag1 == len )&& (flag1 == flag-1))
	{
		return 1;
	}
	else if(len == 0)
	{
		return 0;
	}
	else
	{
		return 0;
	}
}


int checkChoice(char s[])
{
	int len=strlen(s),flag=0,flag1 =0,i,flag2;  
	for(i=0;i<len;i++)
	{
		if(s[i] == ' ')
		{
			flag2 = 1;	
		}
	}
	for(i=0;i<len;i++)
	{
	    if(!(s[i]>='0' && s[i]<='9'))  
		{
			flag=0;
		}
		else
		{
			flag++;
		}
	}
	
	if(len==0 || flag2 == 1)
	{
		return 0;
	}
	if(flag==len )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isSpace(char s[])
{
	int i,count = 0;
	for(i = 0; i < strlen(s); i++)
	{
		if(s[i] == 32)
		{
			count++;
		}
	}
	if(strlen(s) == count)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
