/* 								
   Name : Mahesh Ramdas Dubal 
   Question : Write a C-program to implement the enqueue and dequeue operations on Dequeue.  
   
------------------------------------------------------------------------------------------------------ */

#include<stdio.h>
#include<stdlib.h>
#include"validations.h"
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;
int val;

void enqueueRear(int val)
{
	if(front == 0 && rear == (MAX-1)) //If queue is full
	{
		printf("Queue is full\n");
	}
	else if(front == -1 || rear == -1) //If queue is empty
	{
		front = rear = 0;
		queue[rear] = val;
	}
	else if(rear == MAX-1) //If element inserted at last time  is at end position 
	{
		rear = 0;
		queue[rear] = val;
	}
	else 
	{
		rear++;
		queue[rear] = val;
	}
}

void enqueueFront(int val)
{
	if(front == 0 && rear == (MAX-1)) //If queue is full
	{
		printf("Queue is full\n");
	}
	else if((rear+1)%MAX == front)
	{
		printf("\nQueue is Full\n");
	}
	else if(front == -1 || rear == -1) //If queue is empty
	{
		front = rear = 0;
		queue[front] = val;
	}
	
	else if(front == 0) //front is at first position and rear is in between last and first
	{
		front = MAX -1;
		queue[front] = val;
	}
	else
	{
		front--;
		queue[front] = val;
	}
}

void dequeueFront()
{
	if(front == -1 && rear == -1) //If queue is empty
	{
		printf("Queue is empty\n");
	}
	else if(front == rear)  //if single element present in queue
	{
		printf("Deleted element is : %d\n",queue[front]);
		front = rear = -1;
	}
	else if(front == MAX-1)
	{
		printf("Deleted element is : %d\n",queue[front]);
		front = 0;
	}
	else
	{
		printf("Deleted element is : %d\n",queue[front]);
		front++;
	}
}
void dequeueRear()
{
	if(front == -1 && rear == -1)
	{
		printf("Queue is empty\n");
	}
	else if(front == rear)
	{
		printf("Deleted element is : %d\n",queue[rear]);
		front = rear = -1;
	}
	else if(rear == 0)
	{
		printf("Deleted element is : %d\n",queue[rear]);
		rear = MAX-1;
	}
	else
	{
		printf("Deleted element is : %d\n",queue[rear]);
		rear--;
	}
}


void display()
{
	int i;
	if(front == -1)
	{
		printf("\n Queue is Empty.");
	}
	else
	{
		printf("Queue is : ");
		i = front;
		while(i != rear)
		{
			printf("%d\t",queue[i]);
			i=(i+1)%MAX;
		}
		printf("%d",queue[i]);
		
		/* using for loop
		for(i = front; i != rear; i = (i+1)%MAX)
		{
			printf("%d\t",queue[i]);
		}
		printf("%d",queue[i]);
		*/
	}
}

int main()
{
	int choice, val;
	char a[30], b[30];
	int invalid;
	printf("Double Ended Queue Implementation");
	do
	{
		printf("\n1. Insert using front \n2. Insert using rear \n3. Delete using front \n4. Delete using rear\n5. Display\n6. Exit");
		do
		{
			invalid = 1;
			printf("\n Enter your Choice: ");
			gets(a);
			
			if(checkInteger(a) == 1)
			{
				choice = atoi(a);
				invalid = 1;
			}
			else
			{
				printf("\n Invalid Input");
				invalid = 0;
			}
		}while(invalid == 0);
		
		switch(choice)
		{
			case 1: 
				{
					do
					{
						invalid = 1;
						printf("\n Enter the value to Insert: ");
						gets(b);
						if(checkInteger(b) == 1)
						{
							val = atoi(b);
							invalid = 1;
						}
						else
						{
							printf("\n Invalid Input");
							invalid = 0;
						}
					}while(invalid == 0);
					
					enqueueFront(val);
					break;	
				}
				
			case 2:
				{
					do
					{
						invalid = 1;
						printf("\n Enter the value to Insert: ");
						gets(b);
						if(checkInteger(b) == 1)
						{
							val = atoi(b);
							invalid = 1;
						}
						else
						{
							printf("\n Invalid Input");
							invalid = 0;
						}
					}while(invalid == 0);
					
					enqueueRear(val);
					break;	
				}
					
			case 3:
				{
					dequeueFront();
					break;
				}
			case 4:
				{
					dequeueRear();
					break;
				}
			case 5:
				{
					display();
					break;
				}
				
			case 6:
				{
					exit(0);
					break;
				}
					
			default :
				{
					printf("\n Enter a valid choice\n");
					break;
				}
		}
	}
	while(choice != 6);
	
	return 0;
}
