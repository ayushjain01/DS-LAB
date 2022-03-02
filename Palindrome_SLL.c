#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char letter;
    struct node *next;
} node;

node *createnode(node *next, int letter)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->letter = letter;
    newnode->next = next;
    return newnode;
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
node *convertolist(char string[])
{
    int i = 1;
    node *head = createnode(NULL,string[0]);
    node *ptr = head;
    while (string[i] != '\0')
    {
        ptr->next = createnode(NULL,string[i]);
        ptr = ptr->next;
        i++;
    }
    return head;
}

void check(char word[])
{
    int n = strlen(word);
    node *head = convertolist(word);
    node *rev = reverselist(head);
    node *ptr1 = head;
    node *ptr2 = rev;
    for(int i = 0; i < n; i++)
    {
        if (ptr1->letter != ptr2->letter)
        {
            printf("\n%s is not a Palindrome",word);
            return;
        }
    }
    printf("\n%s is a Palindrome",word);

}
int main()
{
    char word[50];
    printf("\nEnter a word to check : ");
    scanf("%s", word);
    check(word);
}
