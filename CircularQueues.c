#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

void enQueue(int element)
{
    if (((front == rear + 1) || (front == 0 && rear == SIZE - 1)))
        printf("\nCircular Queue is full!! \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}

void deQueue()
{
    int element;
    if (front == -1)
    {
        printf("\nCircular Queue is empty\n");
    }
    else
    {
        element = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        printf("\n Deleted element -> %d \n", element);
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("\nCircular Queue is empty\n");
    else
    {
        printf("\nFront -> %d\n ",front);
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                printf("%d\t", items[i]);
        }
        else
        {
            for (i = 0; i <= rear; i++)
                printf("%d\t", items[i]);
            for (i = front; i <= SIZE - 1; i++)
                printf("%d\t", items[i]);
        }
        printf("\nRear -> %d\n ",rear);

    }
}

int main()
{

    int choice, element;

    while (1)
    {
        printf("\nEnter choice-\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:

            printf("Enter element to be enqueued: ");
            scanf("%d", &element);
            enQueue(element);

            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
        }
    }
}