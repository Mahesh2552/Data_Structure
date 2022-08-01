
/*                            

Question : Write a C-program to implement different operations of circular queue using Array
Name : Mahesh Ramdas Dubal

---------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include"validations.h"

#define SIZE 5

int rear = -1,front = -1,val = 0,size = 0;

int circu_queue[SIZE];

void enqueue(int);
int dequeue();
int count();
void display();

int main()
{
	int choice = 1,elem = 0;
	char str[10];
	
	while(choice != 0)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Count\n4.Display\n0.Exit\n");
	
		int invalid = 1;
		
		while(invalid == 1)
		 {
			printf("\nEnter your choice : ");
			gets(str);
	
			if(checkInteger(str) == 1)
			{
				choice = atoi(str);
				invalid = 0;
			}
			else
			{
				printf("\n\tInvalid choice\n\n");
				invalid = 1;
			}
		 }
		
		switch(choice)
		{
			case 1 :  {
						int invalid = 1;
						while(invalid == 1)
						{
							printf("\nEnter element  : ");
							gets(str);
					
							if(checkInteger(str) == 1)
							{
								elem = atoi(str);
								enqueue(elem);
								invalid = 0;
							}
							else
							{
								printf("\n\tInvalid Number\n\n");
								invalid = 1;
							}
						 }
					 break;
				}
			case 2 : elem = dequeue();
					 printf("\nRemoved element is  %d\n",elem);
				 	 break;
					
			case 3 : elem = count();
					 printf("\nNumber of elements in Queue are %d\n",elem);
					 break;
					
			case 4 : display();
					 break;
					
			case 0 : exit(0);
					 break;
					
			default : printf("\nEnter a valid choice\n");
		}
	}
	return 0;
}

void enqueue(int no)
{
	if(front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
		circu_queue[rear] = no;
		size++;
	}
	else if((rear+1)%SIZE == front)
	{
		printf("\nQueue is Full\n");
	}
	else
	{
		rear = (rear + 1)%SIZE;
		circu_queue[rear] = no;
		size++;
	}
	
	printf("rear = %d\n",rear);
}

int dequeue()
{
	if(front == -1)
	{
		printf("\nQueue is Empty\n");
	}
	else if(front == rear)
	{
		val = circu_queue[front];
		front = -1;
		rear = -1;
		size--;
	}
	else
	{
		val = circu_queue[front];
		front = (front+1)%SIZE;
		size--;
	}
	return val;
}

int count()
{
	return size;
}

void display()
{
	int i = 0;
	
	if(front <= rear)
	{
		for(i = front; i<= rear; i++)
		{
			printf("%d\t",circu_queue[i]);
		}
	}
	else if(front >= rear)
	{
		for(i = front ; i <= SIZE -1 ; i++)
		{
			printf("%d\t",circu_queue[i]);
		}

		for(i = 0 ; i <= rear; i++)
		{
			printf("%d\t",circu_queue[i]); 
		}
	}	
}
