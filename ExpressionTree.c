//Postfix expression - Infix and Prefix and evaluation using Binary Tree

#include <stdio.h>
#include<stdlib.h>
#include <math.h>

#define SIZE 100

typedef struct etree
{
    char data;
    struct etree *right;
    struct etree *left;
}etree;

etree *stack[SIZE];
int top = 0;

void push(etree *node)
{
    stack[++top] = node;
}

etree* pop()
{
    return stack[top--];
}


int verify(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '$') return 1;
    else return 2;
}

void operand(char a){
    etree *newnode;
    newnode = (etree*)malloc(sizeof(etree));
    newnode->data = a;
    newnode->right = NULL;
    newnode->left = NULL;
    push(newnode);
}
void operator(char b){
    etree *newnode;
    newnode = (etree*)malloc(sizeof(etree));
    newnode->data = b;
    newnode->right = pop();
    newnode->left = pop();
    push(newnode);
}

void inorder(etree *root)
{
    if (root == NULL) 
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf(" %c ",root->data);
        inorder(root->right);
    }
}

void preorder(etree *root)
{
    if (root == NULL) 
    {
        return;
    }
    else
    {
        printf(" %c ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int evaluate(etree *root)
{
    int opr = verify(root->data);
    if (opr == 1)
    {
        if (root->data == '+')
        {
            evaluate(root->left) + evaluate(root->right);
        }
        else if (root->data == '-')
        {
            evaluate(root->left) - evaluate(root->right);
        }
        else if (root->data == '*')
        {
            evaluate(root->left) * evaluate(root->right);
        }
        else if (root->data == '/')
        {
            evaluate(root->left) / evaluate(root->right);
        }
        else if (root->data == '^' || root->data == '$')
        {
            pow(evaluate(root->left),evaluate(root->right));
        }
    }
    else if (opr == 2)
    {
        return (root->data - 45);
    }
}

int main()
{
    char postfix[SIZE];
    printf("\nEnter a valid postfix expression : ");
    scanf("%s", postfix);
    for(int i = 0; postfix[i] != '\0'; i++)
    {
        int opr = verify(postfix[i]);
        if (opr == 1) operator(postfix[i]);
        else if (opr == 2) operand(postfix[i]);
    }
    printf("\nInfix Notation : ");
    inorder(stack[top]);
    printf("\nPrefix Notation : ");
    preorder(stack[top]);
    printf("\nResult : %d",evaluate(stack[top]));
}
