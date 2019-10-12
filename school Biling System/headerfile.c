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
        USER *found = (USER*) searchUser(guest,2);
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
        editUser();
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
    char c='m';
    system("cls");
    printf("   ADD TEACHER  ");
    while(c=='m'|| c=='M')
    {
        FILE *fh=fopen("Teachers.DAT","ab+");
        if(fh==NULL)
        {
            exit(1);
        }
        TEACHER newTeacher;
        fflush(stdin);
        printf("\n\tEnter your name :");
        gets(newTeacher.info.name);
        int i=0;
        char ch;
        printf("\nEnter Semester Taken:: ");
        while(i<3)
        {
            ch = getche();
            if(ch==13)
                break;
            if(isdigit(ch))
            {
                newTeacher.semester[i] = ch-48;
                i++;
            }
            else
                break;
        }
        newTeacher.sizeSem = i;
        strcpy(newTeacher.info.ID,generateID('T'));
        printf("\n\tGiven ID ::: ");
        puts(newTeacher.info.ID);
        printf("\n\tEnter your department: ");
        gets(newTeacher.info.dept);
        fflush(stdin);
        printf("Enter Title: ");
        gets(newTeacher.title);
        printf("\n\tEnter salary: ");
        fflush(stdin);
        scanf(" %lf",&newTeacher.salary);

        time(&newTeacher.info.createdOfDate);

        fh=fopen("Teachers.DAT","ab+");//opening a binary file in apend mode
        //fwrite(&st,sizeof(st),1,fp);
        fwrite(&newTeacher,sizeof(TEACHER),1,fh);
        fclose(fh);
        printf("\n\nDo you want to continue with the process(press f or F):");
        fflush(stdin);
        c=getch();
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
void editUser()
{
    int j;
    system("cls");
    printf("\tUSER TYPE");
    printf("\n\t1.Students");
    puts("\n\t2.Teachers");
    printf("Please enter your choice: ");
    j = getch()-48;
    char id[10];
    switch(j)
    {
    case 1:
        {
            printf("Enter the student id:");
            gets(id);
            STUDENT *ff = searchStudent(id);

        }
        break;
    case 2:
        {
            printf("Enter the teacher id:");
            gets(id);
        }
        break;
    default :
        {
            printf("\n\tInvalid password or user name!!!");
        }
    }

}
void resetUserPassword()
{
    system("cls");
    USER tem;
    printf("\tUsername:: ");
    gets(tem.username);
    USER *found = NULL;
    FILE *fp = fopen("users.DAT","rb+");
    if(fp==NULL)
    {
        exit(1);
    }
    found = searchUser(tem,1);

    if(found){
        strcpy(found->password,generateID('P'));
        saveUserData(*found);
        puts("User Password Successfully Reset :)");
    }
    else
        puts("No User Found :(");
    getch();

}
void receiveFee() {}
void displayAllStudents() {}
void displayAllTeachers() {}
void deleteStudent() {}
void deleteTeacher() {}
STUDENT* searchStudent(char *ID)
{
  FILE* fp=fopen("Students.DAT","rb+");
  STUDENT *st = (STUDENT*) malloc(sizeof(STUDENT));
  while(fread(&st,sizeof(STUDENT),1,fp)==1)
  {
      if(!stricmp(st->info.ID,ID))
      {
          fclose(fp);
          return st;
      }
  }
  fclose(fp);
  return NULL;
}
void searchTeacher(char *ID) {}
void* searchUser(USER usr, int opt)
{
    FILE *fp = fopen("users.DAT","rb+");
    if(fp==NULL)
    {
        exit(1);
    }
    USER *tem = (USER*) calloc(1,sizeof(USER));

    while(fread(tem,sizeof(USER),1,fp)==1)
    {
        switch(opt)
        {
        case 1:
            if(!strcmpi(usr.username,tem->username))
                return tem;
            break;
        case 2:
            if(!strcmpi(usr.username,tem->username) && !strcmpi(usr.password,tem->password))
                return tem;
            break;
        }
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

void saveUserData(USER newUser)
{
    FILE *fpr = fopen("users.DAT","rb+");
    if(fpr==NULL)
        return;
    FILE *fpt = fopen("temData.DAT","wb+");

    USER data;
    while(fread(&data,sizeof(USER),1,fpr)==1)
    {
        if(!stricmp(data.username,newUser.username))
        {
            continue;
        }
        else
        {
            fwrite(&data,sizeof(USER),1,fpt);
        }
    }
    fwrite(&newUser,sizeof(USER),1,fpt);
    fclose(fpr);
    fclose(fpt);
}

