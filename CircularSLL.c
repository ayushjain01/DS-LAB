#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    int rollno;
    char name[50];
    struct student *next;
} student;

student *head;
student *searchptr;

int count;
int srollno;
char sname[50];

void LLDemoOptions()
{
    printf("\n*** Circular Singly Linked List Program. Having ONLY 'Insert' & 'Search' & 'Delete' *** \n");
    printf("0.Menu\n");
    printf("1.Search RollNo \n");
    printf("2.Insert At Any Position \n");
    printf("3.Display Students \n");
    printf("4.Delete From Any Position\n");
    printf("5.Quit \n");
}

student *searchStudent(student *head, int srollno)
{
    student *pointer = head;
    if (head == NULL)
        return NULL;
    else
    {
        do
        {
            if (pointer->rollno == srollno)
                return pointer;

            else
                pointer = pointer->next;
        }
        while (pointer != head);
        return NULL;
    }
}
void printstudentdetails(student *head)
{
    if (head == NULL)
    {
        printf("\nStudent Linked List is Empty\n");
    }
    else
    {
        student *pointer = head;
        printf("\nNumber of students in the linked list is: %d\n", count);
        printf("\nHead address - %p\n", head);
        do
        {
            printf("\nStudent RollNo : %d \n", pointer->rollno);
            printf("\nStudent name : %s \n", pointer->name);
            pointer = pointer->next;
            printf("\nNext Student Node : %p \n", pointer);
        }
        while (pointer != head);
    }
}

student *createstudent(student *next)
{
    student *newstudent = (student *)malloc(sizeof(student));
    strcpy(newstudent->name, sname);
    newstudent->rollno = srollno;
    newstudent->next = next;
    count++;
    return newstudent;
}

student *insertany(student *head)
{
    int position;
    int rollposition;
    if (head == NULL)
    {
        printf("\nFirst Node Created\n");
        student *newstudent = createstudent(head);
        head = newstudent;
        head->next = head;
        return head;
    }
    else
    {
        student *posptr = NULL;
        printf("\nWhere do you want to Insert : Enter\n0 for before\n1 for after\n... ");
        scanf("%d", &position);
        if (position == 0)
        {
            printf("\nEnter the Student RollNo you want to insert before : ");
            scanf("%d", &rollposition);
        }
        else if (position == 1)
        {
            printf("\nEnter the Student RollNo you want to insert after : ");
            scanf("%d", &rollposition);
        }
        else
            printf("\n Wrong value for position - enter 0 for before, 1 for after");

        posptr = searchStudent(head, rollposition);

        printf("\n Posptr pointer address->%p and Rollposition is %d", posptr, rollposition);
        if (posptr != NULL)
        {
            if (position == 1 && posptr->next == NULL)
            {
                printf("\n In Insert Any : Insert After End Node - ");
                student *newStudent = createstudent(head);
                posptr->next = newStudent;
            }
            else if (position == 1 && posptr->next != NULL)
            {
                printf("\n In Insert Any : Insert After a Middle Node - ");
                student *newStudent = createstudent(posptr->next);
                posptr->next = newStudent;
                printf("\nPostptr %p Head %p newStudent %p postptr->next %p head->next %p newstudent->next %p",posptr,head,newStudent,posptr->next,head->next,newStudent->next);
            }
            else if (position == 0 && posptr == head)
            {
                printf("\n In Insert Any : Insert Before Head Node - ");
                student *newStudent = createstudent(posptr);
                student *lastStudent = head;
                while (lastStudent->next != head)
                {
                    lastStudent = lastStudent->next;
                    printf("\nlastStudent address->%p and posptr->%p", lastStudent, posptr);
                }
                head = newStudent;
                lastStudent->next = head;
            }
            else
            {
                printf("\n In Insert Any : Insert Before a Middle Node ");
                student *beforeStudent = head;
                while (beforeStudent->next != posptr)
                {
                    beforeStudent = beforeStudent->next;
                    printf("\nbeforeStudent address->%p and posptr->%p", beforeStudent, posptr);
                }
                student *newStudent = createstudent(posptr);
                beforeStudent->next = newStudent;
                printf("\nbeforeStudent address->%p and newStudent->%p", beforeStudent, newStudent);
            }
        }
        else
        {
            printf("\nThe roll no. that you have entered doesn't exist in the linked list.");
        }
        return head;
    }
}

student *deleteany(student *head, int srollno)
{
    student *delptr = searchStudent(head, srollno);
    if (delptr == NULL)
    {
        printf("\nThe roll no. that you have entered doesn't exist in the linked list.");
        return head;
    }
    else
    {
        count--;
        if (count<=0)
        {
            head = NULL;
        }
        else{
            if (delptr == head)
            {
                printf("You are deleting the head node from the linked list.");
                student *lastStudent = head;
                while (lastStudent->next != head)
                    {
                        lastStudent = lastStudent->next;
                    }
                head = head->next;
                lastStudent->next = head;
            }
            else if (delptr->next == NULL)
            {
                printf("You are deleting the tail node from the linked list.");
                student *pointer = head;
                while (pointer->next != delptr)
                {
                    pointer = pointer->next;
                }
                pointer->next = head;
            }
            else
            {
                printf("You are deleting a node from the middle of the linked list.");
                student *pointer = head;
                while (pointer->next != delptr)
                {
                    pointer = pointer->next;
                }
                pointer->next = delptr->next;
            }
            
        }
        free(delptr);
        return head;
    }
}

int main()
{
    head = NULL;
    searchptr = NULL;

    int choice = 0;
    LLDemoOptions();

    while (1)
    {
        printf("\nPlease enter a choice-");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            LLDemoOptions();
            break;
        case 1:
            printf("\nPlease enter a number to search:");
            scanf("%d", &srollno);
            searchptr = searchStudent(head, srollno);
            if (searchptr != NULL)
            {
                printf("\nStudent with RollNo %d found. Name is %s", searchptr->rollno, searchptr->name);
            }
            else
            {
                printf("\nStudent with RollNo %d not found.", srollno);
            }
            break;

        case 2:
            printf("\nEnter the Student RollNo ");
            scanf("%d", &srollno);
            printf("\nEnter the Student Name ");
            scanf("%s", sname);
            head = insertany(head);
            break;

        case 3:
            printstudentdetails(head);
            break;

        case 4:
            printf("\nEnter the Student RollNo to delete");
            scanf("%d", &srollno);
            head = deleteany(head, srollno);
            break;
        case 5:
            exit(0);
        default:
            printf("\nPlease Enter a valid choice\n");
        }
    }
}
