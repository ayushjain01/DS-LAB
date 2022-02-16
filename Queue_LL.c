#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

void enqueue(node *head, int n)
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

void dequeue(node *head)
{	
	node *temp;
    if (head==NULL)
	{
		printf("\nQueue Underflow\n");
	}
	else if(head->next == NULL)
	{   free(head);
	    head = NULL;
	}
	else
	{
		temp=head;
		head=head->next;
		free(temp);
	}

}
void display(node *head)
{
	node *ptr;
	if (head==NULL)
	{
		printf("\nQueue Underflow\n");
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
		printf("\n Menu \n 1. Enqueue  \n 2. Dequeue  \n 3. Display  \n 4. Exit \nEnter  : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				printf("\n Enter the data ");
				scanf("%d", &(data));
				enqueue(head, data);
				break;

			case 2: 
				dequeue(head);
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
