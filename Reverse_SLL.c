#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;
node *searchptr;

node *createnode(node *next,int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = next;
    return newnode;
}

node *insert(node *head,int data)
{
    int position;
    int rollposition;
    if (head == NULL)
    {
        node *newnode = createnode(head,data);
        head = newnode;
        return head;
    }
    else
    {
        node *pointer = head;
        while (pointer->next != NULL)
        {
                pointer = pointer->next;
        }
        node *newnode = createnode(NULL,data);
        pointer->next = newnode;
        return head;
    }
}
node * reverse(node* head)
{
	struct node* prev = NULL;
	struct node* current = head;
	struct node* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
    return head;
}
void display(node *head)
{
    node *pointer = head;
    while (pointer != NULL)
    {
        printf("%d --> ", pointer->data);
        pointer = pointer->next;
    }
}

int main()
{
    head = NULL;
    int count,data;
    printf("\nEnter number of elements in linked list : ");
    scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
        printf("\nEnter Data : ");
        scanf("%d", &data);
        head = insert(head,data);
    }
    printf("\nLinked List before reversing : \n");
    display(head);
    head = reverse(head);
    printf("\nLinked List after reversing : \n");
    display(head);
}