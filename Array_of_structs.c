//Array of structs using malloc
#include<stdio.h>
#include <stdlib.h>
struct student
    {
        char fname[50];
        int roll;

    } ;

int main()
{
    
    int n;
    printf("Enter number of students-");
    scanf("%d",&n);
    int i;
    struct student* students;
    students = (struct student*)malloc(n * sizeof(struct student));
    for (i = 0; i < n; i++)
    {

        printf("Enter first name :");
        scanf("%s",students[i].fname);
        printf("Enter roll number  :");
        scanf("%d",&students[i].roll);

    }

    for (i = 0; i < n; i++)
        printf("First Name: %s, Roll number: %d\n",students[i].fname,students[i].roll);

    return (0);
}
