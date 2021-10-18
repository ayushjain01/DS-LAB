//Dynamic Memory Allocation
#include <stdio.h>
#include <stdlib.h>
struct person {
   char fname[30];
   int age;
};
int main(){
   struct person *ptr;
   ptr = (int*) malloc(sizeof(struct person));
   printf("Enter first name and age respectively: ");
   scanf("%s %d", (ptr)->fname, &(ptr)->age);
   printf("Name: %s\tAge: %d", (ptr)->fname, (ptr)->age);
   return 0;
}
 
