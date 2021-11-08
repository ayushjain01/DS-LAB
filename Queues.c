#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue_arr[MAX];
int rear=-1;
int front=-1;

void enqueue(int item);
int dequeue();
void display();
int isFull();
int isEmpty();

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Enqueue\n");
                printf("2.Dequeue\n");
                printf("3.Display\n");
                printf("4.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1:
                        printf("\nInput the element for adding in queue : ");
                        scanf("%d",&item);
                        enqueue(item);
                        break;
                case 2:
                        item=dequeue();
                        printf("\nDeleted element is  %d\n",item);
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }
        }

        return 0;

}
void enqueue(int item)
{
        if( rear == MAX-1 )
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if( front == -1 )
                front=0;
        rear=rear+1;
        queue_arr[rear]=item ;
}
int dequeue()
{
        int item;
        if( front==-1 || front==rear+1 )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        item=queue_arr[front];
        front=front+1;
        return item;
}

void display()
{
        int i;
        if ( front==-1 || front==rear+1)
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue is :\n\n");
        for(i=front;i<=rear;i++)
                printf("%d  ",queue_arr[i]);
        printf("\n\n");
}
