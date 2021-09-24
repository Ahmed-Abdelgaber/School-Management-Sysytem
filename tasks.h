#ifndef _TASKS_H_
#define _TASKS_H_
#define ADD_NEW_STUDENT 1
#define DELETE_STUDENT 2
#define VIEW_STUDENTS 3
#define EDIT_STUDENT 4
#define VIEW_STUDENTS_RANK 5
#define EDIT_STUDENT_SCORE 6
#define COMPUTER_SCIENCE 0
#define MATH 1
#define PHYSICS 2
#define HISTORY 3
#define DESIGEN 4
#define MECHANICS 5
#include <stdbool.h>


typedef struct student
{
    int ID;
    int phoneNumber;
    int dateOfBirth[3];
    int scores[6];
    char address[100];
    char name[100];
    struct student*pPrev;
    struct student*pNext;
} student;

typedef struct myList
{
    student *phead;
    student *ptail;
    unsigned int listSize;
} List;

/* self-referential structure */
typedef struct treeNode {
    struct treeNode *leftPtr; /* pointer to left subtree */
    int data;
    int studenID;
    char name[100]; /* node value */
    struct treeNode *rightPtr; /* pointer to right subtree */
}TreeNode; /* end structure treeNode */
typedef TreeNode* TreeNodePtr;

/*functions prototypes*/
char mainMenu();
void creatList(List *pl);
void newStudent(List * pl,int ID,int phoneNumber,int dateOfBirth[],char address[],char name[]);
void deleteStudent(List *pl,int ID);
void studentList(List * pl);
void studentEdit(List * pl,int ID,int unit);
void rankStudent (List *pl,int subject);
void studentScore (List *pl,int ID);
void allStudentsScore (List *pl);
bool isEmpty(List * pl);
void insertDegree( TreeNodePtr *treePtr, int value , int studentID , char name[100] ); // change
void inOrder( TreeNodePtr treePtr );
#endif // _TASKS_H_
