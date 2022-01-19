//Addition of two polynomials using  linked lists

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

//Each element of the List is a term of the polynomial
typedef struct term{
    int coeff; 
    int expo; 
    struct term *next;
}term ;

term *create_term(int c, int e)
{
    term *new_term;
    new_term =(term*)malloc(sizeof(term));
    new_term->coeff = c;
    new_term->expo = e;
    new_term->next = NULL;
    return new_term;
}


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
            term *new_term; 
            new_term = create_term(coeff,deg);  //assuming the first term has the highest exponent and so on..
            head = new_term;   //the first term is the head of the list
            temp = head;
        for(int i = deg-1; i>=0; i--)
        {
            printf("\nEnter the Coefficient of term 1 (exponent = %d) :",i);
            scanf("%d",&coeff);
            term *new_term;
            new_term = create_term(coeff,i); 
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

term *add_poly(term *poly1, term *poly2)
{
    term *poly, *term, *temp;
    while(!((poly1 == NULL) && (poly2 == NULL)))   
    {
        if(poly1->expo > poly2->expo)
        {
            term = create_term(poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        }
        else if(poly1->expo < poly2->expo)
        {
            term = create_term(poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        }
        else
        {
            term = create_term(poly1->coeff+poly2->coeff, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (poly == NULL)
        {
            temp = term;
            poly = temp;
        }
        else
        {
            temp->next = term;
            temp = temp->next;
        }
    }
    return poly;
}

int main(){
    
    int x, res;
    term *poly1, *poly2, *poly;
    poly1 = create_polynomial();
    poly2 = create_polynomial();
    if (poly1 == NULL || poly2 == NULL)
    {
        exit(0);
    }
    else{
        printf("\n--------------------------------");
        printf("\nThe polynomial 1 you created is : ");
        display_polynomial(poly1);
        printf("\nThe polynomial 2 you created is : ");
        display_polynomial(poly2);
        poly = add_poly(poly1,poly2);
        printf("\nSum : ");
        display_polynomial(poly);
    }
    return 0;
}