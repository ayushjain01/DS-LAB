//Static memory allocation
#include <stdio.h>
#define SIZE 50

// create struct with person1 variable
struct Empl {
  char name[SIZE];
  int emplid;
  float salary;
} empl1;

int main() {

  printf("Enter Employee Name-");
  gets(empl1.name);
  printf("Enter Employee ID-");
  scanf("%d",&empl1.emplid);
  printf("Enter Employee Salary-");
  scanf("%f",&empl1.salary);

  // print struct variables
  printf("Name: %s\n", empl1.name);
  printf("Employee Id.: %d\n", empl1.emplid);
  printf("Salary: %.2f", empl1.salary);

  return 0;
}
