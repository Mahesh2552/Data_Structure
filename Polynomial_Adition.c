/* 
Question : Write a c program to find addition of two polynomials using array data structure.
*/

#include<stdio.h>
#include<stdlib.h>
#include"validations.h"

void Poly_Addition(int Arr[],int Brr[],int d1,int d2)
{
    int i = 0;

	if(d1 == d2)
	{

		for(i = d1; i >= 0; i--)
		{
			if(i != 0)
			{
				printf("%dx^%d ",Arr[i]+Brr[i],i);
				printf(" + ");
			}
			else
			{
				printf("%d",Arr[i]+Brr[i]);  //to print addition of constant element 
			}
		}	
	}	
	else if(d1 < d2)
	{
		for(i = d2;i != d1; i--)
		{
			printf("%dx^%d ",Brr[i],i); // print elements as it is which have greater power than d1
			printf(" + ");
		}

		for(i = d1;i >= 0; i--)
		{
			if(i != 0)
			{
				printf("%dx^%d ",Arr[i]+Brr[i],i);  
				printf(" + ");
			}
			else
			{
				printf("%d",Arr[i]+Brr[i]);     // to print addition of constant element
			}
		}
	}
	else 
	{
		for(i = d1;i != d2; i--)
		{	
			printf("%dx^%d ",Arr[i],i);
			printf(" + ");
		}
		
		for(i = d2;i >= 0; i--)
		{
			if(i != 0)
			{
				printf("%dx^%d",Arr[i]+Brr[i],i);	
				printf(" + ");
			}
			else
			{
				printf("%d",Arr[i]+Brr[i]);
			}
		}
	}
}

void Display(int arr[],int brr[],int d1,int d2)
{
	int i = 0,k = 0;
	
	if(d1 == d2)
	{
		printf("\t");
		for(i = d1; i >=0 ;i--)
		{
			if(i != 0)
			{
				printf("%dx^%d ",arr[i],i);
				printf(" + ");
			}
			else
			{
				printf("%d",arr[i]);  
			}
		}
		
		printf("\n\n+\n\n");
		
		printf("\t");
		for(i = d2; i >=0 ;i--)
		{
			if(i != 0)
			{
				printf("%dx^%d ",brr[i],i);
				printf(" + ");
			}
			else
			{
				printf("%d",brr[i]);  
			}
		}
	}
	
	else if(d1 > d2)
	{
		printf("\t");
		for(i = d1; i >=0 ;i--)
		{
			if(i != 0)
			{
				printf("%dx^%d ",arr[i],i);
				printf(" + ");
			}
			else
			{
				printf("%d",arr[i]);  
			}
		}
		
		printf("\n  + \n");
		
		printf("\t");
		for(i = d1 ; i >=0 ;i--)
		{
			if(i > d2)
			{
				printf("%dx^%d ",k,i);
				printf(" + ");
			}
			else
			{
				if(i != 0)
				{
					printf("%dx^%d ",brr[i],i);
					printf(" + ");
				}
				else
				{
					printf("%d",brr[i]);  
				}
			}	
		}
	}
	
	else if(d1 < d2)
	{
		printf("\t");
		for(i = d2; i >= 0 ;i--)
		{
			if(i > d1)
			{
				printf("%dx^%d ",k,i);
				printf(" + ");
			}
			else
			{
				if(i != 0)
				{
					printf("%dx^%d ",arr[i],i);
					printf(" + ");
				}
				else
				{
					printf("%d",arr[i]);  
				}
			}
		}
		
		printf("\n  + \n");
		
		printf("\t");
		for(i = d2 ; i >=0 ;i--)
		{
			if(i != 0)
			{
				printf("%dx^%d ",brr[i],i);
				printf(" + ");
			}
			else
			{
				printf("%d",brr[i]);  
			}
		}	
	}
}
	
int main()
{
	int i = 0,m = 0,n = 0;
	char str[10];
	
	printf("\n\t Addition of polynomials\n");
	printf("\t______________________________\n");
	
	int invalid = 1;
	while(invalid == 1)
	{
		printf("\n\tEnter the degree of the polynomial 1:");
		gets(str);

		if(checkInteger(str) == 1 && atoi(str) >= 0)
		{
			m = atoi(str);
			invalid=0;
		}
		else
		{
			printf("\n\tInvalid Number\n\n");
			invalid = 1;
		}
	}

    int poly1[m];

    printf("\n\tEnter coefficients of your first polynomial :\n");

	for (i = 0;i <= m; i++)
	{
		invalid = 1;
		while(invalid == 1)
		{
			printf("\n\tEnter the coefficient of x^%d: ",i);
			gets(str);

			if(checkInteger(str) == 1)
			{
				poly1[i] = atoi(str);
				invalid = 0;
			}
			else
			{
				printf("\n\tInvalid Number\n");
				invalid = 1;
			}
		}
	}
	
	printf("\n___________________________________________________________________\n\n\t");
	
	invalid = 1;
	while(invalid == 1)
	{
		printf("\n\tEnter the degree of the polynomial 2:");
		gets(str);
		if(checkInteger(str) == 1 && atoi(str)>=0)
		{
			n = atoi(str);
			invalid = 0;
		}
		else
		{
			printf("\n\tInvalid Number\n\n");
			invalid = 1;
		}
	}
    
    int poly2[n];
    
	printf("\n\tEnter coefficients of your Second polynomial :\n");
	
	for (i = 0; i <= n; i++)
	{
		invalid = 1;
		while(invalid == 1)
		{
			printf("\n\tEnter the coefficient of x^%d: ",i);
			gets(str);

			if(checkInteger(str) == 1)
			{
				poly2[i] = atoi(str);
				invalid = 0;
			}
			else
			{
				printf("\n\tInvalid Number\n");
				invalid = 1;
			}
		}
	}
	
	printf("\n___________________________________________________________________\n\n\t");
	printf("\nResult : \n\n");

	Display(poly1,poly2,m,n);
	
	printf("\n___________________________________________________________________\n\n\t");

	Poly_Addition(poly1,poly2,m,n);
	
	printf("\n");

	return 0;
}
