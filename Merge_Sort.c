
/*                            

Question : Write a C-program to implement Merge Sort Algorithm.
Name : Mahesh Ramdas Dubal


---------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include"validations.h"

void merge(int *a,int lb,int mid,int ub)
{
	int i,j,k,b[ub+1];
	
	i = lb;
	j = mid + 1;
	k = lb;
	
	while(i <= mid && j <= ub)
	{
		if(a[i] <= a[j])
		{
			b[k] = a[i];
			i++;
			k++;
		}
		else
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}
	
	if(i > mid) //if extra elements of right sublist
	{
		while(j <= ub)
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}
	else       //if extra elements of right sublist
	{
		while(i <= mid)
		{
			b[k] = a[i];
			i++;
			k++;
		}
	}
	
	for(k = lb; k <= ub; k++) //for copying sorted elements into original array 
	{
		a[k] = b[k];
	}
}

int *mergesort(int *a,int lb,int ub)
{
	if(lb < ub)
	{
		int mid;
		mid = (lb+ub)/2;
		mergesort(a,lb,mid); //for left sublist
		mergesort(a,mid+1,ub); // for right sublist
		merge(a,lb,mid,ub);  // for merging
	}
	
	return a;
}

int main()
{
	int n,i;
	char str[10];
	
	int invalid = 1;
	
	while(invalid == 1)
	{
		printf("Enter number of elements : ");
		gets(str);
		
		if(checkInteger(str) == 1 && atoi(str)>=0)
		{
			n = atoi(str);
			invalid = 0;
		}
		else
		{
			printf("\n\tInvalid Input\n\n");
			invalid = 1;
		}
	}
	
	int A[n];
	
	printf("Enter your Array Elements :\n ");
	
	for(i = 0; i < n; i++)
	{
		int invalid = 1;
		while(invalid == 1)
		{
			printf("A[%d] = ",i);
			gets(str);
			
			if(checkInteger(str) == 1)
			{
				A[i] = atoi(str);
				invalid = 0;
			}
			else
			{
				printf("\n\tInvalid Number\n\n");
				invalid = 1;
			}
		}
	}
	
	printf("Your Array Elements Are :\n ");
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t",*(A+i));
	}
	
	int *ptr;
	
	ptr = mergesort(A,0,n-1); //(Array,lowerbound,Upperbound)
	
	
	printf("\nSorted Elements are : \n");
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t",*(ptr+i));
	}
	
	return 0;
}
