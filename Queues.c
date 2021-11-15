#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int myqueue[SIZE], front = -1, rear = -1;

void enqueue(int element)
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        myqueue[rear] = element;
    }
}

void dequeue()
{
    if (front == -1)
        printf("\nQueue Underflow\n");
    else
    {
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    if (rear == -1)
        printf("\nQueue is Empty!!!\n");
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", myqueue[i]);
    }
    printf("\n");
}

int main()
{
    int element, ch;

    while (1)
    {
        printf("\nEnter choice-\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n...");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be enqueued: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
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
