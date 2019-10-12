#ifndef HEADERFILE_H_INCLUDED
#define HEADERFILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>



typedef struct user
{
    char username[50];
    char password[50];
    char userType;
}USER;

typedef struct personInfo
{
    char name[100];
    char ID[10];
    char dept[5];
    time_t createdOfDate;
}Info;

typedef struct student
{
    Info info;
    int semester;
    double fee;
    double dueFee;
    double penalty;

}STUDENT;

typedef struct teacher
{
    Info info;
    char title[10];
    int semester[3];
    int sizeSem;
    double salary;
}TEACHER;

///---BEGIN
void loginForm();

///---Interfaces
void StudentInterface(USER st);
void TeacherInterface(USER th);
void AdminInterface();

///---Student
void profilStudent();
void editPasswordStudent();

///---Teacher
void profilTeacher();
void displaySemesterStudent();
void paiementHistory();
void editPasswordTeacher();

///---Admin
void addTeacher();
void addStudent();
void editUser();
void resetUserPassword();
void receiveFee();
void displayAllStudents();
void displayAllTeachers();
void deleteStudent();
void deleteTeacher();
void searchStudent(char *ID);
void searchTeacher(char *ID);
void* searchUser(USER usr, int opt);


///---Mechanisms
char* generateID(char userType);



#endif // HEADERFILE_H_INCLUDED
