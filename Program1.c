/*Pass by Value, Pass by Reference, Global and Local Variable*/

#include <stdio.h>
int n = 10;  //global variable
void fun1 (int a, int b)  
{  //local variables 
    int temp;   
    temp = a;  
    a=b;  
    b=temp;  
    printf("Values in fun1 a = %d, b = %d\n",a,b); 
}  
void fun2(int *a) {    
    printf("Before adding value inside fun2 num=%d \n",*a); 
    (*a) += n;    
    printf("After adding value inside func2 num=%d \n", *a);    
}      

int main()  
{  
    int a = 10;  
    int b = 20;  
    int x=100;  
    printf("Before calling fun1 a = %d, b = %d\n",a,b); 
    fun1(a,b);  
    printf("After calling fun1 a = %d, b = %d\n",a,b); 
      
    printf("Before calling fun2 x=%d \n", x);    
    fun2(&x);  
    printf("After calling fun2 x=%d \n", x); 
}  
