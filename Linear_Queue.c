
/*                            

Question :Write a C-prorgam to implement different operations of linear queue using Array
Name : Mahesh Ramdas Dubal

---------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
#include"validations.h"

int front = -1, rear = -1,size = 0,val = 0;
int queue[SIZE];

void enqueue(int);
int dequeue();
int count();
void display();

int main()
{
	int choice = 1,elem = 0;
	char str[10];
	printf("Linear Queue Implementation\n");
	while(choice != 0)
	{
		printf("\n");
		printf("\n1.Enqueue\n2.Dequeue\n3.Count\n4.Display\n0.Exit\n");
	
		int invalid = 1;
		while(invalid == 1)
		 {
			printf("\nEnter your choice : ");
			gets(str);
	
			if(checkInteger(str) == 1)
			{
				choice=atoi(str);
				invalid=0;
			}
			else
			{
				printf("\n\tInvalid choice\n\n");
				invalid = 1;
			}
		 }
		
		switch(choice)
		{
			case 1 : {
						 int invalid = 1;
						 while(invalid == 1)
						 {
							printf("\nEnter element  : ");
							gets(str);
					
							if(checkInteger(str) == 1)
							{
								elem=atoi(str);
								enqueue(elem);
								invalid=0;
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
	if(front == -1 && rear == -1 )
	{
		front = 0;
		rear = 0;
		queue[rear] = no;
		size++;
	}
	else if(rear == SIZE-1)
	{
		printf("\nQueue is Full\n");
	}
	else
	{
		rear = rear + 1;
		queue[rear] = no;
		size++;
	}
	printf("front = %d",front);
	printf("\trear = %d",rear);
}


int dequeue()
{
	if(rear == -1 || front > rear)
	{
		printf("\nQueue is Empty\n");
	}
	else if(front == rear)
	{
		val = queue[front];
		front = -1;
		rear = -1;
		size--;
	}
	else
	{
		val = queue[front];
		front = front+1;//front++
		size--;
	}
	
	printf("front = %d",front);
	printf("\trear = %d",rear);
	return val;
}

int count()
{
	return size;
}

void display()
{
	int i = 0;
	if(front == -1 && rear == -1)
	{
		printf("\nNo elements.\n");
	}
	else
	{
		for(i = front; i <= rear; i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}

	


