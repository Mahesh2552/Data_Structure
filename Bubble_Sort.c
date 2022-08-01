/*                           

Question : Write a C-program to implement Bubble Sort Algorithm.
Name : Mahesh Ramdas Dubal

---------------------------------------------------------------------------------------------------*/

#include<stdio.h>

int *bubblesort(int *a,int size)
{
	int i,j,temp,flag;
	
	for(i = 0; i < size-1; i++)
	{
		flag = 0;
		for(j = 0; j < size-1-i; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
		}
		if(flag == 1)
		{
			break;
		}
	}
	return a;
}
int main()
{
	int n,i;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	
	int A[n];
	
	printf("Enter your Array Elements :\n ");
	
	for(i = 0; i < n; i++)
	{
		printf("A[%d] = ",i);
		scanf("%d",&A[i]);
	}
	
	int *ptr;
	
	ptr = bubblesort(A,n);
	
	printf("\nSorted Elements are : \n");
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t",*(ptr+i));
	}
	
	return 0;
}
