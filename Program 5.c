// malloc, calloc, realloc

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n1,n2, i, *ptr1, *ptr2, *ptr3, sum = 0;

  printf("Enter Size: ");
  scanf("%d", &n1);

  ptr1 = (int*) malloc(n1 * sizeof(int));
  ptr2 = (int*) calloc(n1, sizeof(int));
printf("Addresses of previously allocated memory using malloc:\n");
  for(i = 0; i < n1; ++i)
    printf("%p\n",ptr1 + i);

  printf("Addresses of previously allocated memory using calloc:\n");
  for(i = 0; i < n1; ++i)
    printf("%p\n",ptr2 + i);

  printf("\nEnter the new size: ");
  scanf("%d", &n2);

  ptr3 = realloc(ptr1, n2 * sizeof(int));

  printf("Addresses of newly allocated memory:\n");
  for(i = 0; i < n2; ++i)
    printf("%p\n", ptr3 + i);
  


  return 0;
}
