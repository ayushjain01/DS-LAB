#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

void push(node *head, int n)
{
		node *temp, *ptr;
		temp=(node*)malloc(sizeof(node));		
		temp->next = NULL;
		temp->data = n;

		if (head==NULL)
		{
			head=temp;
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
		}
}

void pop(node *head)
{	
	node *ptr, *temp;
	if (head==NULL)
	{
		printf("\nStack Underflow\n");
	}

	else if(head->next == NULL)
	{   
		free(head);
	    head = NULL;
	}
	else
	{
		ptr=head;
		while (ptr->next!=NULL)
		{
			temp=ptr;
			ptr= ptr->next;
		}
		temp->next=NULL;
		free(ptr);
	}
}
void display(node *head)
{
	node *ptr;
	if (head==NULL)
	{
		printf("\nStack Underflow\n");
	}
	else
	{
		ptr=head;
		while (ptr!=NULL)
		{
			printf(" %d --> ",ptr->data);
			ptr=ptr->next;
		}
	}
}


void main()
{
	int ch,data;
	node *head = NULL;
	while (1)
	{
		printf("\n Menu \n 1. Push  \n 2. Pop  \n 3. Display  \n 4. Exit \nEnter  : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				printf("\n Enter the data ");
				scanf("%d", &(data));
				push(head, data);
				break;

			case 2: 
				pop(head);
				break;
			case 3: 
				display(head);
				break;
			case 4: 
				exit(0);
			case 5:
				printf("\nInvalid Choice\n");
		}
	}
}