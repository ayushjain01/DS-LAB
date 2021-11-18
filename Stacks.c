#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int top = -1;
int mystack[SIZE];

void push(int element)
{

    if (top == SIZE - 1)
    {
        printf("\nStack Overflow\n");
        return;
    }
    else
    {
        mystack[++top] = element;
        return;
    }
}

int pop()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        return mystack[top--];
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", mystack[i]);
        }
        printf("\n");
    }
}

int main()
{

    int element, element_deleted, ch;

    while (1)
    {
        printf("\nEnter choice-\n");
        printf("1: Push\n2: Pop\n3: Display\n4: Exit\n...");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be pushed: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            element_deleted = pop();
            if (element_deleted == 0)
                printf("\nStack Underflow\n");
            else
                printf("\nElement Popped is %d\n", element_deleted);
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
