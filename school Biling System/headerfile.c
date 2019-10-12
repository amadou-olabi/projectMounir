#include "headerfile.h"

///---BEGIN
void loginForm()
{
    USER guest;
    printf("\tUsername:: ");
    gets(guest.username);
    printf("\tPassword:: ");
    gets(guest.password);

    if(!strcmpi(guest.username,"admin") && !strcmpi(guest.password,"123"))
    {
        AdminInterface();
    }
    else
    {
        USER *found = (USER*) searchUser(guest);
        if(found)
        {
            switch(found->userType)
            {
            case 'S':
                StudentInterface(*found);
                break;
            case 'T':
                TeacherInterface(*found);
                break;
            }
        }
    }
}

///---Interfaces
void StudentInterface(USER st)
{

}
void TeacherInterface(USER th) {}
void AdminInterface()
{
    system("cls");
    puts("\n\t\t1:: Add Teacher");
    puts("\n\t\t2:: Add Student");
    puts("\n\t\t3:: Edit UserInfo");
    puts("\n\t\t4:: Reset User Password");
    puts("\n\t\t5:: Receive Tuition Fee");
    puts("\n\t\t6:: Display User");
    puts("\n\t\t7:: Delete User");
    puts("\n\t\t8:: Search User");

    int ch = getch()-48;
    switch(ch)
    {
    case 1:
        addTeacher();
        break;
    case 2:
        addStudent();
        break;
    case 3:

        break;
    case 4:
        resetUserPassword();
        break;
    case 5:
        receiveFee();
        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    }
}

///---Student
void profilStudent() {}
void editPasswordStudent() {}

///---Teacher
void profilTeacher() {}
void displaySemesterStudent() {}
void paiementHistory() {}
void editPasswordTeacher() {}

///---Admin
void addTeacher()
{
    char c='M';
    system("cls");
    printf("   ADD TEACHER  ");
    while(c=='m'|| c=='M')
    {
        FILE *fh=fopen("Teacher.DAT","rb+");
        if()
    }
}
void addStudent()
{
    char a='f';
    system("cls");
    printf("\n\t                    ***********************                  ");

    printf("\n\t**********************  ADDING STUDENTS  *******************");

    printf("\n\t                    ***********************                 ");

    while(a=='f' || a=='F')
    {
        FILE *fp= fopen("students.DAT", "ab+");
        STUDENT newStudent;
        fflush(stdin);
        printf("\n\tEnter your name :");
        gets(newStudent.info.name);
        printf("\n\tEnter your class:");
        fflush(stdin);
        scanf(" %d",&newStudent.semester);
        strcpy(newStudent.info.ID,generateID('S'));
        printf("\n\tGiven ID ::: ");
        puts(newStudent.info.ID);
        printf("\n\tEnter your department: ");
        gets(newStudent.info.dept);
        printf("\n\tEnter Fee to paid:");
        fflush(stdin);
        scanf(" %lf",&newStudent.fee);

        time(&newStudent.info.createdOfDate);

        newStudent.dueFee = newStudent.fee;
        newStudent.penalty = 0.0;

        fp=fopen("students.DAT","ab+");//opening a binary file in apend mode
        //fwrite(&st,sizeof(st),1,fp);
        fwrite(&newStudent,sizeof(STUDENT),1,fp);
        fclose(fp);
        printf("\n\nDo you want to continue with the process(press f or F):");
        fflush(stdin);
        a=getch();
    }
}
void editUser() {}
void resetUserPassword() {}
void receiveFee() {}
void displayAllStudents() {}
void displayAllTeachers() {}
void deleteStudent() {}
void deleteTeacher() {}
void searchStudent(char *ID) {}
void searchTeacher(char *ID) {}
void* searchUser(USER usr)
{
    FILE *fp = fopen("users.DAT","rb+");
    if(fp==NULL)
    {
        exit(1);
    }
    USER *tem = (USER*) calloc(1,sizeof(USER));

    while(fread(tem,sizeof(USER),1,fp)==1)
    {
        if(!strcmpi(usr.username,tem->username))
            return tem;
    }
    fclose(fp);
    return NULL;
}

char* generateID(char userType)
{
    time_t t;
    srand((unsigned) time(&t));
    int num = rand();
    char *id = (char*) malloc(sizeof(char)*10);
    id[0] = userType;
    id[1] = '\0';
    char numC[10];
    itoa(num,numC,16);
    strcat(id,numC);
    return id;
}
