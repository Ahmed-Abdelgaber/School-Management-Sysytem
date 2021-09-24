#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"tasks.h"
int main()
{
    List system;
    creatList(&system);
    int  ID;
    int  phoneNumber;
    char name[100];
    char address[100];
    int dateOfBirth[3];
    int unit;
    char index;
    int subject = 0;
    while (1)
    {
        char choice = mainMenu();
        switch (choice)
        {
        case ADD_NEW_STUDENT:
            {
            printf("Please Enter The student ID : \n");
            scanf("%d",&ID);
            printf("Please Enter The student Name : \n");
            fflush(stdin);
            fflush(stdout);
            gets(name);
            printf("Please Enter The student Phone Number : \n");
            scanf("%d",&phoneNumber);
            printf("Please Enter The student Address : \n");
            fflush(stdin);
            fflush(stdout);
            gets(address);
            printf("Please Enter The student Date of birth (Year) : \n");
            scanf("%d",&dateOfBirth[2]);
            printf("Please Enter The student Date of birth (Month) : \n");
            scanf("%d",&dateOfBirth[1]);
            printf("Please Enter The student Date of birth (Day) : \n");
            scanf("%d",&dateOfBirth[0]);
            newStudent(&system,ID,phoneNumber,dateOfBirth,address,name);
            break;
            }
        case DELETE_STUDENT:
            {

            if (isEmpty(&system))
            {
                printf("================================\n");
                printf("There are no students!!!!!!!!!!!\n");
                printf("================================\n");

            }
            else
            {
                printf("PLease enter the ID : ");
                scanf("%d",&ID);
                deleteStudent(&system,ID);
            }

            break;
            }
        case VIEW_STUDENTS:
            {
            studentList(&system);
            break;
            }
        case EDIT_STUDENT:
            {

            if (isEmpty(&system))
            {
                printf("================================\n");
                printf("There are no students!!!!!!!!!!!\n");
                printf("================================\n");

            }
            else
            {
                printf("Please enter the ID of student : \n");
                scanf("%d",&ID);
                printf("1.Edit Name\n2.Edit Address\n3.Edit Phone Number\n4.Edit Date of birth\n");
                scanf("%d",&unit);
                studentEdit(&system,ID,unit);

            }
            break;
            }
        case VIEW_STUDENTS_RANK:
            {
            printf("Please choose the subject\n1.computer science\n2.Math\n3.Physics\n4.History\n5.design\n6.mechanics\n");
            scanf("%d",&subject);
            rankStudent(&system,(subject-1));
            break;
            }
        case EDIT_STUDENT_SCORE:
            {

            if (isEmpty(&system))
            {
                printf("================================\n");
                printf("There are no students!!!!!!!!!!!\n");
                printf("================================\n");
            }
            else
            {
                printf("Do you want to edit scores for a particular students? y/n >> ");
                fflush(stdin);
                fflush(stdout);
                scanf("%c",&index);
                if (index == 'y'|| index == 'Y')
                {
                    printf("Please enter the ID of the student : ");
                    scanf("%d",&ID);
                    studentScore(&system,ID);
                }
                else if (index == 'n'|| index == 'N')
                {
                    allStudentsScore(&system);
                }
                else
                {
                    printf("Please choose yes or no !!!!!!");
                }

                break;

            }
            }
        default:
            {
            printf("WRONG CHOICE!!!!!! .. Please try again\n");
            break;

            }
        }

    }

    return 0;
}
