// Implement the following using singly linked list: 
// Count the number of nodes in the list
// Reverse the list. 

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void display(node *head)
{
   
    node *pointer = head;
    while (pointer != NULL)
    {
        printf(" %d -> ", pointer->data);
        pointer = pointer->next;
    }
    
}

node *createnode(node *next, int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = next;
    return newnode;
}

int countnodes(node *head)
{
    int count = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

node *reverselist(node *head)
{
    node* prev = NULL;
	node* current = head;
	node* next = NULL;
	while (current != NULL) 
    {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
    return prev;
}

int main()
{
    int data = 0;
    printf("\nEnter Data for Head Node : ");
    scanf("%d", &data);
    node *head = createnode(NULL,data);
    node *ptr = head;
    while (1)
    {
        printf("\nEnter Data (-1 to stop insertion) : ");
        scanf("%d", &data);
        if (data == -1) break;
        else
        {
            ptr->next = createnode(NULL,data);
            ptr = ptr->next;
        }
    }
    printf("\nInput List : ");
    display(head);
    int count = countnodes(head);
    printf("\nNumber of Nodes in List : %d",count);
    ptr = reverselist(head);
    printf("\nReversed List : ");
    display(ptr);
}
