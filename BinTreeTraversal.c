//Creation and Traversal - Inorder, Preoder and Postorder

#include <stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}node;

int count = 0;

node *create(node *root, int data)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        count++;
    }
    else
    {
        if (data < root->data)
        {
            root->left = create(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = create(root->right, data);
        }
        else
        {
            printf("\nData already present in the tree.");
        }
    }
    return root;

}


void display(struct node * root, int i)
{
    int j;
    if (root == NULL) 
    {
        return;
    }
    else
    {
        display(root->right,i+1);
        for(j = 1 ; j <= i ; j++) 
        {   
            printf("\t");
        }
        printf("%d (%d:%d)\n",root->data, i,j);
        display(root->left,i+1);
    }
    
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


int main()
{
    struct node *root = NULL;
    int choice, item, n, i;
    while(1)
    {
        printf("\n\nBinary Tree Operations");
        printf("\n1. Create");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Display");
		printf("\n6. Exit");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            root = NULL;
            printf("\nEnter number of nodes - ");
            scanf("%d",&n);
            count = 0;
            while (count <n)
            {
                printf("\nEnter data for node %d : ", i);
                scanf("%d",&item);
                root = create(root,item);
            }
            break;
        case 2:
            printf("\nInorder Traversal : \n");
            inorder(root);
            break;
        case 3:
            printf("\nPreorder Traversal : \n");
            preorder(root);
            break;
        case 4:
            printf("\nPostorder Traversal : \n");
            postorder(root);
            break;
        case 5:
			display(root,1); 
            break;
		case 6: 
			exit(0); 
            break;
        default:
            printf("\nInvalid Option");
            break;
        }
    }
    return 0;
}
