
/* 									
   Name : Mahesh Ramdas Dubal 
   Question : Write a C program to implemenet operations on binary search tree.
   
------------------------------------------------------------------------------------------------------ */

#include<stdio.h>
#include<stdlib.h>

struct treenode
{
	int data;
	struct treenode *left,*right;
};


//Inorder Traversal (left-data-right)

void inorder(struct treenode *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		inorder(root->left);        //To Traverse left
		printf("%d\t",root->data);    //To Traverse data
		inorder(root->right);        //To Traverse right
	}
}


//Preorder Traversal (data-left-right)

void preorder(struct treenode *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		printf("%d\t",root->data);    //To Traverse data
		preorder(root->left);        //To Traverse left
		preorder(root->right);        //To Traverse right
	}
}


//Postorder Traversal (left-right-data)

void postorder(struct treenode *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		postorder(root->left);        //To Traverse left
		postorder(root->right);        //To Traverse right
		printf("%d\t",root->data);    //To Traverse data
	}
}


//Insertion of node

struct treenode *insert(struct treenode *newnode,int item)
{
	if(newnode == NULL)     //If tree is empty
	{
		newnode = (struct treenode *)malloc(sizeof(struct treenode));
		newnode->data = item;
		newnode->left = newnode->right = NULL;
	}
	// To inseet element at corrrect position in BST
	else if(item < newnode->data)
	{
		newnode->left = insert(newnode->left,item);
	}
	
	else if(item > newnode->data)
	{
		newnode->right = insert(newnode->right,item);
	}
	
	return newnode;
}

// To find the inorder successor
struct treenode *findMin(struct treenode *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(root->left == NULL)
	{
		return root;
	}
	else
	{
		return findMin(root->left);
	}
}


// To find the inorder predecessor
struct treenode *findMax(struct treenode *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(root->right == NULL)
	{
		return root;
	}
	else
	{
		return findMax(root->right);
	}
}


//Deletion of node

struct treenode *deleteNode(struct treenode *root,int item)
{
	struct treenode *temp;
	int choice;
	
	if(root == NULL)
	{
		printf("\nTree is empty !!!\n");
	}
	//To find desired node to delete
	else if(item < root->data)
	{
		root->left = deleteNode(root->left,item);
	}
	else if(item > root->data)
	{
		root->right = deleteNode(root->right,item);
	}
	else 
	{
		if(root->left && root->right)  //If the node has two children
		{
			printf("\n1.Inorder Successor\n2.Inorder Predecessor\n");
			printf("\nEnter your choice :  ");
			scanf("%d",&choice);
			if(choice == 1)
			{
				temp = findMin(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right,temp->data);
			}
			else if(choice == 2)
			{
				temp = findMax(root->left);
				root->data = temp->data;
				root->left = deleteNode(root->left,temp->data);
			}
			else
			{
				printf("\n\tEnter valid choice !!\n");
			}
		}
		else		// only one child
		{
			temp = root;
			if(root->left == NULL)
			{
				root = root->right;
			}
			else if(root->right == NULL)
			{
				root = root->left;
			}
			
			free(temp);
			temp = NULL;
		}
	}
	
	return root;
}

struct treenode *search(struct treenode *root,int item)
{
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		if(item < root->data)
		{
			return search(root->left,item);
		}
		else if(item > root->data)
		{
			return search(root->right,item);
		}
	}
	
	return root;
}
int main()
{
	int choice= 0,elem = 0;
	struct treenode *root = NULL;
	
	printf("\n\tImplentations of Binary Search Tree\n");
	printf("_______________________________________________\n\n");
	/*printf("\nEnter the element of root : ");
	scanf("%d",&elem);
	root = insert(root,elem);*/
	
	while(choice != 5)
	{
		printf("\n1.Insert the element\n2.Delete the element\n3.Display\n4.Search\n5.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			{
				printf("\nEnter the element  : ");
				scanf("%d",&elem);
				root = insert(root,elem);
				break;
			}
			
			case 2:
			{
				printf("\nEnter the element of root : ");
				scanf("%d",&elem);
				root = deleteNode(root,elem);
				break;
			}
			
			case 3:
			{
				printf("\nElements of BST\n");
				printf("\n1.Inorder\n2.Preorder\n3.Postorder\n");
				printf("\nEnter your choice: ");
				scanf("%d",&choice);
				printf("\nElements of BST\n");
				
				switch(choice)
				{
					case 1:
					{
						inorder(root);
						break;
					}
					
					case 2:
					{
						preorder(root);
						break;
					}
					
					case 3:
					{
						postorder(root);
						break;
					}
					
					default: printf("\n\tEnter valid choice\n");
				}
				
				break;
			}
			
			case 4:
			{
				printf("\nEnter the element of root : ");
				scanf("%d",&elem);
				if(search(root,elem) != NULL)
				{
					printf("\n%d is found in given BST.\n",elem);
				}
				else
				{
					printf("\n%d is not found !!\n");
				}
				
				break;
			}
			
			case 5: exit(0);
			
			default: printf("\n\tEnter valid choice\n");
		}
		printf("\n_______________________________________________\n\n");
	}
	
	return 0;
}
