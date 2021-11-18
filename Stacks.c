#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int top;
int s[SIZE];
int item;

void push()
{
 if(top == SIZE -1)
 {
     printf("Stack Overlflow\n");
     return;
 }
 s[++top] = item;
 
}
int pop()
{
    int item_del;
 if(top == -1)
 {
   return 0;
 }
 item_del = s[top];
 top--;
 return item_del;
}
void display()
{
    int i;
    if(top == -1)
 {
   printf("Stack is Empty\n");
   return ;
 }
 printf("Contents of the Stack :\n");
 for (i = 0; i<=top;i++)
 {
     printf("%d\n",s[i]);
 }
}

void peek()
{
 if(top == -1)
 {
   printf("Stack Underflow\n");
   return ;
 }
 printf("Item on top -> %d\n",s[top]);
}

int main() {
  int item_del, choice;
  top = -1;
  for (;;)
  {
      printf("Enter the choice -\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Quit\n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1:
            {
                printf("Enter element-");
                scanf("%d",&item);
                push();
                break;
            }
        case 2:
            {
                item_del = pop();
                if (item_del == 0)
                {
                    printf("Stack Underflow\n");
                }
                else
                {
                    printf("Item Deleted : %d\n",item_del);
                }
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                peek();
                break;
            }
        case 5:
            {
                exit(0);
                break;
            }
        default:
            {
                printf("Invalid Choice. Please Try Again");
            }
        }
  
}
return 0;
}
