#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node ;
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

int search( node* root , int num){
    if(root == NULL)
    return 0;

    else {
        if(num == root->data)
        return 1;

        else if(num > root->data)
        return search(root->right , num);

        else if(num < root->data)
        return search(root->left , num);
    }
}
 node* minValueNode( node* new)
{
    node* current = new;
 
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
 
 node* delete( node* root, int data)
{

    if (root == NULL)
    {
        return NULL;
    
    }
    if (data < root->data)
    {
        root->left = delete(root->left, data);
        return root;
    }
    else if (data > root->data)
    {
        root->right = delete(root->right, data);
        return root;

    }
    else {
        if (root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
    else{
        node* temp = minValueNode(root->right);
 
        root->data = temp->data;
 
        root->right = delete(root->right, temp->data);
        return root;
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

int main(){
    node* root = NULL;
    int num ,ch,item;
    printf("1. Insert \n 2. Search \n 3. Delete \n 4. Display \n 5. Exit\n");

    while(1){
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("\n Enter item to insert : ");
                scanf("%d",&item);
                root = create(root,item);
                break;

            case 2:
                printf("\nEnter data to search for : ");
                scanf("%d",&item);
                if(search(root,item))
                    printf("\n%d found!\n",item);
                else
                    printf("\n%d not found!\n",item);
                break;

            case 3:
                if(root == NULL)
                printf("\nBST is empty\n");
            else {
                printf("\nEnter data to delete : ");
                scanf("%d",&item);

                if(search(root, item) == 0)
                printf("\nCannot Delete : None not found\n");
                else {
                    root = delete(root, item);
                    printf("\n%d Deleted\n",item);
                }
                }
                break;

            case 4:
                display(root,1);
                break;
            case 5:
                exit(0);
            default :
            printf("\nInvalid Choice\n");
        }
    }
    return 0;
}
