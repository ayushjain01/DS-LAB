//Refer Postfix_Eval_Algorithm.txt 

#include <stdio.h>
#include <math.h>
#include <string.h>

void push(double item, int *top, double stack[])
{
    (*top)++;
    stack[*top] = item;
}

double pop(double stack[], int* top)
{
    double item;
    item = stack[*top];
    (*top)--;

    return item;
}

double evaluate(double op1, double op2, char symbol)
{
    switch(symbol){
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        case '^':
        case '$':
            return pow(op1,op2);
    }
}

int isDigit(char symbol)
{
	return (symbol >= '0' && symbol <= '9');
}

void main()
{
    int top = -1;
    char expression[50], symbol;
    double stack[50],res, op1, op2;

    printf("\nEnter a valid postfix expression (avoid whitespaces): ");
    scanf("%s",expression);

    int length = strlen(expression);

    for(int i = 0; i < length; i++)
    {
        symbol = expression[i];
        if (isDigit(symbol))
        {   
            push(symbol - '0',&top,stack);
        }
        else
        {
            op2 = pop(stack,&top);
            op1 = pop(stack,&top);
            res = evaluate(op1,op2,symbol);

            push(res,&top,stack);
        }
        
    }
    res = pop(stack,&top);
    printf("\nResult : %lf",res);
}
