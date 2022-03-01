#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int myqueue[SIZE], front = -1, rear = -1, priority;

void enqueue(int priority)
{
    int i = rear;
   
    if (front == -1)
        {
            front = 0;
        }
    while(i>=0 && priority < myqueue[i])
    {
        myqueue[i+1] = myqueue[i];
        i--;
    }
    myqueue[i+1] = priority;
    rear++;
}
int isfull(){
    if (rear == SIZE -1) return 1;
    else return 0;
}
int isempty(){
    if (front == -1) return 1;
    else return 0;
}

void dequeue()
{
    
    front++;
    if (front > rear)
    {
            front = rear = -1;
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
            if (isfull())
            {
                printf("\nQueue is full\n");
            }
            else{
                printf("\nEnter Priority: ");
                scanf("%d", &priority);
                enqueue(priority);
            }
            break;
        case 2:
            if (isempty())
            {
                printf("\nQueue is empty\n");
            }
            else{
                dequeue(priority);
            }    
            break;
        case 3:
            if (isempty())
            {
                printf("\nQueue is empty\n");
            }
            else{
                display();
            }    
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
        }
    }
}
