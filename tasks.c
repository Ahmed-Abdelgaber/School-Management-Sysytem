#include "tasks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void creatList(List *pl)
{
    pl->phead = NULL;
    pl->ptail = NULL;
    pl->listSize = 0;
}
char mainMenu()
{
    char choice = 0;
    printf("\nWelcome to our system :D\n");
    printf("========================\n");
    printf("1. Add new student\n2. Delete student\n3. View students\n4. Edit student\n5. View students rank\n6. Edit student score\n");
    printf("========================\n");
    printf("Please choose what do you wanna do : ");
    scanf("%d",&choice);
    return choice;
}
void newStudent(List * pl,int ID,int phoneNumber,int dateOfBirth[],char address[],char name[])
{
    //step 1: Create place to accept new student
    student *pn = (student *)malloc(sizeof(student));

    //Check memory to add new student
    if (pn == NULL)
    {
        printf("Sorry we can not accept more students\n");
        return;
    }
    //Check the ID
    printf("Checking ID............ ");

    student *temp = pl->phead;
    while(temp != NULL)
    {
        if (temp->ID == ID)
        {
            printf("This ID is already exits !!!!!!!");
            free(pn);
            return;
        }
        temp = temp->pNext;
    }

    //step 2: Inserting student data
    pn->pPrev = NULL;
    pn->pNext = NULL;
    pn->ID = ID;
    pn->phoneNumber = phoneNumber;
    int i;
    for (i=0; i<3; i++)
    {
        pn->dateOfBirth[i]= dateOfBirth[i];
    }
    strcpy(pn->address,address);
    strcpy(pn->name,name);


    //Adding the student object to the system
    if (isEmpty(pl)) // List is Empty
    {
        pl->phead = pn;
        pl->ptail = pn;
    }
    else
    {
        temp = pl->phead;
        while(temp != NULL && (strcmp(temp->name,pn->name)!= 1))
        {
            temp = temp->pNext;
        }
        if (temp == pl->phead) // Insert at head
        {
            pn->pNext = pl->phead; //step 1
            pl->phead->pPrev = pn; // step 2
            pl->phead = pn;        //step 3
        }
        else if (temp == NULL) //Insert at tail
        {
            pn->pPrev = pl->ptail; //step 1
            pl->ptail->pNext = pn; //step 2
            pl->ptail = pn;        //step 3
        }
        else //insert at any where else ( at middle )
        {
            pn->pNext = temp;        //step 1
            pn->pPrev = temp->pPrev; // step 2
            temp->pPrev->pNext = pn; //step 3
            temp->pPrev = pn;        //step 4
        }

    }
    printf("INSERTED SUCCEFULLY\n");
    pl->listSize++;
    //printf("SIZE : %d\n",pl->listSize);
}
bool isEmpty(List *pl)
{
    return (pl->phead == NULL);

}
void studentList(List * pl)
{
    if (isEmpty(pl))
    {
        printf("================================\n");
        printf("There are no students!!!!!!!!!!!\n");
        printf("================================\n");

        return;
    }
    int i = 1;
    student *temp;
    for (temp = pl->phead; temp != NULL; temp = temp->pNext)
    {
        printf("==============================\n");
        printf("Student Number %d\n",i);
        printf("Student ID : %d\n",temp->ID);
        printf("Student Name : %s\n",temp->name);
        printf("Student Phone Number : 0%d\n",temp->phoneNumber);
        printf("Student Date of birth : %d/%d/%d\n",temp->dateOfBirth[2],temp->dateOfBirth[1],temp->dateOfBirth[0]);
        printf("Student Address : %s\n",temp->address);
        //printf("Scores : \n1.%d\n2.%d\n3.%d\n4.%d\n5.%d\n6.%d\n",temp->scores[0],temp->scores[1],temp->scores[2],temp->scores[3],temp->scores[4],temp->scores[5]);
        printf("==============================\n");
        i++;
    }
}
void studentEdit(List * pl,int ID,int unit)
{

    student *temp = pl->phead;
    int i = 1;
    int flag = 1;
    while (temp != NULL )
    {
        if (temp->ID == ID)
        {
            flag = 0;
            break;
        }
        temp = temp->pNext;
        i++;
    }
    if (flag)
    {
        printf("Student is not exist!!");
    }
    else
    {

        printf("Student number %d \n",i);
        printf("ID : %d \n",temp->ID);
        printf("Name : %s \n",temp->name);
        printf("Phone Number : 0%d \n",temp->phoneNumber);
        printf("Address : %s \n",temp->address);
        printf("Date of birth : %d/%d/%d\n",i,temp->dateOfBirth[2],temp->dateOfBirth[1],temp->dateOfBirth[0]);
        int  phoneNumber;
        char name[100];
        char address[100];
        int dateOfBirth[3];
        switch (unit)
        {
        case 1:
            printf("Please enter the new name : \n");
            fflush(stdin);
            fflush(stdout);
            gets(name);
            strcpy(temp->name,name);
            break;
        case 2:
            printf("Please enter the new address : \n");
            fflush(stdin);
            fflush(stdout);
            gets(address);
            strcpy(temp->address,address);
            break;
        case 3:
            printf("Please enter the new phone number : \n");
            scanf("%d",&phoneNumber);
            temp->phoneNumber = phoneNumber;
            break;
        case 4:
            printf("Please enter the new date of birth : \n");
            printf("New Year : \n");
            scanf("%d",&dateOfBirth[2]);
            temp->dateOfBirth[2] = dateOfBirth[2];
            printf("New Month : \n");
            scanf("%d",&dateOfBirth[1]);
            temp->dateOfBirth[1] = dateOfBirth[1];
            printf("New Day : \n");
            scanf("%d",&dateOfBirth[0]);
            temp->dateOfBirth[0] = dateOfBirth[0];
            break;
        default:
            printf("WRONG CHOICE!!!");
            break;
        }
    }
    printf("UPDATED SUCCEFULLY");
}
void deleteStudent(List *pl,int ID)
{

    student *temp = pl->phead;
    int flag = 1;
    while (temp != NULL )
    {
        if (temp->ID == ID)
        {
            flag = 0;
            break;
        }
        temp = temp->pNext;
    }
    if (flag)
    {
        printf("Student is not exist!!");
    }
    else
    {
        if (pl->phead == pl->ptail) //only one node
        {
            free(pl->phead);
            pl->phead = NULL;
            pl->ptail = NULL;
        }
        else if (temp == pl->phead) //in case of deleting head
        {
            //step 1: assign the new head
            pl->phead = pl->phead->pNext;
            //step 2: assign NULL to prev of the new head
            pl->phead->pPrev= NULL;
            //step 3: free old head using copy (temp)
            free(temp);
        }
        else if (temp == pl->ptail) // in case of deleting tail
        {
            //assign new tail
            pl->ptail = pl->ptail->pPrev;
            //assign NULL to the next of the new tail
            pl->ptail->pNext = NULL;
            //free old tail
            free(temp);
        }
        else //in case of anynode
        {
            temp->pPrev->pNext = temp->pNext;
            temp->pNext->pPrev = temp->pPrev;
            free(temp);
        }
        printf("DELETED SUCCEFULLY");
        pl->listSize--;
    }


}
void studentScore (List *pl,int ID)
{

    student *temp = pl->phead;
    int i;

    printf("Searching for student..........\n");
    while (temp != NULL&&temp->ID != ID)
    {
        temp = temp->pNext;//Searching for the ID
    }
    if (temp != NULL)
    {
        printf("Please enter the scores in the following order.....  \n");
        printf("1.computer science : ");
        scanf("%d",&temp->scores[0]);
        printf("2.Math : ");
        scanf("%d",&temp->scores[1]);
        printf("3.Physics : ");
        scanf("%d",&temp->scores[2]);
        printf("4.History : ");
        scanf("%d",&temp->scores[3]);
        printf("5.design : ");
        scanf("%d",&temp->scores[4]);
        printf("6.mechanics : ");
        scanf("%d",&temp->scores[5]);
        printf("UPDATED SUCCEFULLY");
    }
    else
    {
        printf("Student does not exist!!!!!!!");
    }
}
void allStudentsScore (List *pl)
{
    student *temp = pl->phead;
    int i = 1;
    printf("Please enter the scores in the following order.....  \n");
    while (temp != NULL)
    {
        printf("Please enter scores for student number : \n%d.%s with ID : %d \n",i,temp->name,temp->ID);
        printf("1.computer science : ");
        scanf("%d",&temp->scores[0]);
        printf("2.Math : ");
        scanf("%d",&temp->scores[1]);
        printf("3.Physics : ");
        scanf("%d",&temp->scores[2]);
        printf("4.History : ");
        scanf("%d",&temp->scores[3]);
        printf("5.design : ");
        scanf("%d",&temp->scores[4]);
        printf("6.mechanics : ");
        scanf("%d",&temp->scores[5]);
        printf("UPDATED SUCCEFULLY\n");
        temp = temp->pNext;
        i++;

    }

}
void insertDegree( TreeNodePtr *treePtr, int degree ,int studentId, char name[100])
{
     /* if tree is empty */
	 if ( *treePtr == NULL ) {
		 *treePtr =(TreeNode*) malloc( sizeof( TreeNode ) );

		 /* if memory was allocated then assign data */
		 if ( *treePtr != NULL ) {
			 ( *treePtr )->data = degree;
			 ( *treePtr )->studenID = studentId;
			  strcpy((*treePtr)->name,name);
			 ( *treePtr )->leftPtr = NULL;
			 ( *treePtr )->rightPtr = NULL;
		 } /* end if */
		 else {
		     printf( "%d not inserted. No memory available.\n", degree );
		 } /* end else */
	 } /* end if */
	 else { /* tree is not empty */

		/* data to insert is less than data in current node */
		if ( degree <= ( *treePtr )->data ) {
			insertDegree( &( ( *treePtr )->leftPtr ), degree ,studentId,name);
		} /* end if */
		/* data to insert is greater than data in current node */
		else if ( degree > ( *treePtr )->data ) {
			insertDegree( &( ( *treePtr )->rightPtr ), degree ,studentId,name);
		} /* end else if */
 	} /* end else */
}
void inOrder( TreeNodePtr treePtr )
{
    /* if tree is not empty then traverse */
	if ( treePtr != NULL ) {
	inOrder( treePtr->leftPtr );
	printf("=============\n");
	printf("Name  :  %s\n",treePtr->name);
	printf("ID    :  %d\n",treePtr->studenID);
    printf("Score :  %d\n", treePtr->data );
	printf("=============\n");
	inOrder( treePtr->rightPtr );
	} /* end if */
}
void rankStudent (List *pl,int subject)
{
    TreeNodePtr rootPtr = NULL; /* tree initially empty */
    student *temp = pl->phead;
    int i;
    int localDegree;
    for (i=0;i<pl->listSize;i++)
    {
        localDegree = temp->scores[subject];
        insertDegree(&rootPtr,localDegree,temp->ID,temp->name);
        temp = temp->pNext;
    }
    inOrder(&rootPtr);
}
