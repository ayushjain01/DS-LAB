// Find the Smallest Number in the list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createnode(node *next, int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = next;
    return newnode;
}

int smallest(node *head)
{
    int small = head->data;
    node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data <small)
        {
            small = ptr->data;
        }
        ptr = ptr->next;
    }
    return small;
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
    int small = smallest(head);
    printf("\nSmallest Number in the List : %d",small);
}
