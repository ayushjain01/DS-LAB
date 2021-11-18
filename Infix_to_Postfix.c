//Refer Infix_Postfix_Algorithm.txt 

#include<stdio.h>
#include<stdlib.h>      
#include<ctype.h>
#include<string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char symbol)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = symbol;
	}
}

char pop()
{
	char symbol ;

	if(top <0)
	{
		printf("Stack Underflow");
	}
	else
	{
		symbol = stack[top];
		top = top-1;
		return(symbol);
	}
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int priority(char symbol)
{
	switch(symbol)
	{
		case ')':	return 0;
		
		case '(':	return 1;
		
		case '+':
		case '-':	return 2;
		
		case '*':
		case '/':	return 3;
		
		case '$':
		case '^':	return 4;
	}
}


void convert(char infix[], char postfix[])
{ 
	int i, j;
	char symbol;
	char x;

	push('(');                              
	strcat(infix,")");                  

	i=0;
	j=0;
	symbol=infix[i];         

	while(symbol != '\0')        
	{
		if(symbol == '(')
		{
			push(symbol);
		}
		else if( isalpha(symbol))
		{
			postfix[j] = symbol;              
			j++;
		}
		else if(is_operator(symbol) == 1)        
		{
			x=pop();
			while(is_operator(x) == 1 && priority(x)>= priority(symbol))
			{
				postfix[j] = x;                  
				j++;
				x = pop();                       
			}
			push(x);
			

			push(symbol);                 
		}
		else if(symbol == ')')         
		{
			x = pop();                   
			while(x != '(')                
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 	printf("\nInvalid infix Expression.\n");       
			exit(1);
		}
		i++;
		symbol = infix[i]; 
}
	postfix[j] = '\0'; 

}

int main()
{
	char infix[SIZE], postfix[SIZE];         
	printf("\nEnter Infix expression : ");
	scanf("%s",infix);

	convert(infix,postfix);                   
	printf("Postfix Expression: ");
	puts(postfix);                     

	return 0;
}
