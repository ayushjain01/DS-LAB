/*Pass by Value, Pass by Reference, Global and Local Variable*/

#include <stdio.h>
int a = 10;   //gloabl variable
int fun1(int num)
{
    return num + a;
}
int fun2(int *num)
{
    int a = 20;//local variable
    return *num + a;
}
int main() {
    int num = 100;  //local variable
    int res1,res2;
    res1 = fun1(num); //pass by value
    res2 = fun2(&num); //pass by reference
    printf("Result 1 = %d\nResult 2 = %d",res1,res2);
    return 0;
}
