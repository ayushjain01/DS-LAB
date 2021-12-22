//Stores the coefficients of a polynomial of degree 'n' in a linked list(singly) and evaluates the polynomial for a given value of x.

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

//Each element of the List is a term of the polynomial
typedef struct term{
    int coeff; 
    int expo; 
    struct term *next;
}term ;

//accepts the coefficients of the individual terms of polynomial and stores them in the linked list
term *create_polynomial(){
        term *temp, *head;
        temp = NULL;
        int coeff;
        int deg;
        printf("\nEnter Degree of Polynomial : ");
        scanf("%d",&deg);
        if (deg<=0)
        {
            printf("\nInvalid Degree of Polynomial.");
            return NULL;
        }
        else{
            
            printf("\nEnter the Coefficient of term 1 (exponent = %d) :",deg);
            scanf("%d",&coeff);
            term *new_term = (term*) malloc(sizeof(term));
            new_term->coeff = coeff;
            new_term->expo = deg; //assuming the first term has the highest exponent and so on..
            new_term->next= NULL;
            head = new_term;   //the first term is the head of the list
            temp = head;
        for(int i = deg-1; i>=0; i--)
        {
            printf("\nEnter the Coefficient of term 1 (exponent = %d) :",i);
            scanf("%d",&coeff);
            term *new_term = (term*) malloc(sizeof(term));
            new_term->coeff = coeff;
            new_term->expo = i;
            new_term->next= NULL;
            temp->next = new_term;    
            temp = new_term;
        }
        return head;
    }
}
      
void display_polynomial(term *head){
    term *temp = head;
    while(temp != NULL){
        if(temp->next != NULL){
            printf("(%dx^%d) + ",temp->coeff,temp->expo);
            temp = temp->next;
        }
        else{
            printf("(%dx^%d) ",temp->coeff,temp->expo);   //printing the last term 
                                                        //(the if block above prints the terms with a plus '+' sign)
            temp = temp->next;
        }
    }
}

int evaluate_polynomial(term *head, int x)
{
    int res = 0;
    term *temp = head;
    while (temp != NULL)
    {
        res = res + (pow(x,temp->expo)*(temp->coeff));
        temp = temp->next; 
    }
    return res;
}

int main(){
    
    int x, res;
    term *head;
    head = create_polynomial();
    if (head == NULL)
    {
        exit(0);
    }
    else{
        printf("\n--------------------------------");
        printf("\nThe polynomial you created is : ");
        display_polynomial(head);
        printf("\nEnter the value of x :");
        scanf("%d",&x);
        res = evaluate_polynomial(head,x);
        printf("\nResult : %d",res);
    }
    return 0;
}
