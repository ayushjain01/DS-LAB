#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    int rollno;
    char name[20];
    struct student *next;
    struct student *prev;
} student;
student *head, *tail;
student *searchptr;

int count;
int srollno;
char sname[20];

void LLDemoOptions()
{
    printf("\n*** Doubly Linked List Program. Having ONLY 'Insert' & 'Search' & 'Delete' *** \n");
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
        while (pointer != NULL)
        {
            if (pointer->rollno == srollno)
                return pointer;

            else
                pointer = pointer->next;
        }
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
        printf("\nTail address - %p\n", tail);
        while (pointer != NULL)
        {
            printf("###############################################################################");
            printf("\nPrevious Student Node : %p\n", pointer->prev);
            printf("\nStudent RollNo : %d \n", pointer->rollno);
            printf("\nStudent name : %s \n", pointer->name);
            pointer = pointer->next;
            printf("\nNext Student Node : %p \n", pointer);
            printf("###############################################################################");
        }
    }
}

student *createstudent(student *next, student *prev)
{
    student *newstudent = (student *)malloc(sizeof(student));
    strcpy(newstudent->name, sname);
    newstudent->rollno = srollno;
    newstudent->next = next;
    newstudent->prev = prev;
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
        student *newstudent = createstudent(head, tail);
        head = newstudent;
        tail = head;
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

        printf("\n Posptr pointer address->%d and Rollposition is %d", posptr, rollposition);
        if (posptr != NULL)
        {
            if (position == 1 && posptr->next == NULL)
            {
                printf("\n In Insert Any : Insert After End Node - ");
                student *newStudent = createstudent(NULL, posptr);
                posptr->next = newStudent;
                tail = newStudent;
            }
            else if (position == 1 && posptr->next != NULL)
            {
                printf("\n In Insert Any : Insert After a Middle Node - ");
                student *newStudent = createstudent(posptr->next, posptr);
                newStudent->next->prev = newStudent;
                posptr->next = newStudent;
            }
            else if (position == 0 && posptr == head)
            {
                printf("\n In Insert Any : Insert Before Head Node - ");
                student *newStudent = createstudent(head, NULL);
                head->prev = newStudent;
                head = newStudent;
            }
            else
            {
                printf("\n In Insert Any : Insert Before a Middle Node ");
                student *newStudent = createstudent(posptr, posptr->prev);
                posptr->prev->next = newStudent;
                posptr->prev = newStudent;
                printf("\nposptr->prev->next address->%d and newStudent->%d", posptr->prev->next, posptr->prev);
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
        if (delptr == head)
        {
            printf("You are deleting the head node from the linked list.");
            delptr->next->prev = NULL;
            head = delptr->next;
        }
        else if (delptr->next == NULL)
        {
            printf("You are deleting the tail node from the linked list.");
            delptr->prev->next = NULL;
            tail = delptr->prev;
        }
        else
        {
            printf("You are deleting a node from the middle of the linked list.");
            delptr->prev->next = delptr->next;
            delptr->next->prev = delptr->prev;
        }
        free(delptr);
        return head;
    }
}

int main()
{
    head = NULL;
    tail = NULL;
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
