#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;  
    struct node *right;
}node ;


node *create(){

    int data;
    node *ptr;
        printf("\nEnter data (-1 for no data):\t");
    scanf("%d",&data);
    if (data == -1) return NULL;
    else{
        ptr = (node *)malloc(sizeof(node));
        ptr->data = data;
        printf("\nEnter Left Child Node ");
        ptr->left = create();
        printf("\nEnter Right Child Node ");
        ptr->right = create();
    }
    return ptr;
}

void inorder(node *root)
{
    if (root == NULL) 
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("| %d |",root->data);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if (root == NULL) 
    {
        return;
    }
    else
    {
        printf("| %d |",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root == NULL) 
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("| %d |",root->data);

    }
}



void main(){
    
    node *root = NULL;
    root = create();
    printf("\nInorder Traversal\n");
    inorder(root);
    printf("\nPostorder Traversal\n");
    postorder(root);
    printf("\nPreorder Traversal\n");
    preorder(root);

    
}
