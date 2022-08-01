/* 									
   Name : Mahesh Ramdas Dubal 
   Question : Write a c-program to implement linear search algorithm.
   
------------------------------------------------------------------------------------------------------ */


#include<stdio.h>

int linearSearch(int arr[],int size,int value)
{
	int i;
	
	for(i = 0; i < size ; i++)
	{
		if(arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int *sortArray(int *a,int size)
{
	int i,j,temp,max;
	
	for(i = 0;i < size; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if(a[i]<a[j])
			{
				max = a[j];
			}
			else
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	return a;
}

int main()
{
	int n,i,val,choice;
	printf("Enter your Array size : ");
	scanf("%d",&n);
	
	int A[n];
	
	printf("Enter your Array elements : \n");
	
	
	for(i = 0; i < n; i++)
	{
		printf("A[%d] = ",i);
		scanf("%d",&A[i]);
		printf("\n");
	}
	
	printf("Enter element to serach in Array : ");
	scanf("%d",&val);
	
	printf("\nEnter 1 to find element in given array without sorting\n\nEnter 2 to find element in array after sorting\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1 : {
					int k = linearSearch(A,n,val);
					if(k == -1)
					{
					 	printf("Your element %d is not present in Array.\n");
					}
					else
					{  //Here we consider position means index
					 	printf("Your element %d is present at %d position in Array.\n",val,k);
					}
					break;
			     }
				 
				 
		case 2 : {
					int *b = sortArray(A,n);
		
					printf("\nSorting elements are : \n");
					for(i = 0; i < n; i++)
					{
						printf("%d\t",*(b+i));
					}
				
					int k = linearSearch(b,n,val);
				
					if(k == -1)
					{
						printf("\nYour element is not present in your array\n");
					}
					else
					{
						printf("\nYour element %d is present at %d position in sorted Array\n",val,k);
					}
				 	break;
				 }
		
		default : printf("\nEnter a valid choice\n"); 
		
	}
	
	return 0;
}
