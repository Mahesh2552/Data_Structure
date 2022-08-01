/*                            

Question : Write a C-program to implement Insertion Sort Algorithm.
Name : Mahesh Ramdas Dubal

---------------------------------------------------------------------------------------------------*/

#include<stdio.h>

int *insertionsort(int *a,int size)
{
	int i,j,temp;
	
	for(i = 1; i < size; i++)
	{
		temp = a[i],j = i-1;
		while(a[j] > temp && j >= 0)
		{
			a[j+1] = a[j];
			j--;
		}
		
		a[j+1] = temp;
	}

	return a;
}

int main()
{
	int n,i;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	
	int A[n];
	
	printf("Enter your Array Elements : \n");
	
	for(i = 0; i < n; i++)
	{
		printf("A[%d] = ",i);
		scanf("%d",&A[i]);
	}
	
	int *ptr = insertionsort(A,n);
	
	printf("Sorted Elements are : \n");
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t",*(ptr+i));
	}
	
	return 0;
}

