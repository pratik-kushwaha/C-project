 #include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct password
{
    char name[20];
    char password[30];
};
int main()
{
    gotoxy(15,8);
    printf("***** Password Keeper *****");
    gotoxy(19,15);
    printf("Press any key to continue :");
    getch();
    menu();
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("***** MENU *****");
    gotoxy(10,5);
    printf("Select a task to perform from the following");
    gotoxy(10,7);
    printf("1. Add a new password");
    gotoxy(10,8);
    printf("2. View saved passwords");
    gotoxy(10,9);
    printf("3. Search for a password");
    gotoxy(10,10);
    printf("4. Change a password");
    gotoxy(10,11);
    printf("5. Delete a password");
    gotoxy(10,12);
    printf("6. Exit");
    gotoxy(10,15);
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("You've entered a wrong choice!");
    }
}
void add()
{
    FILE *fp;
    struct password pwd;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("***** ADD A PASSWORD *****");
        gotoxy(10,5);
        printf("Enter details below ");
        gotoxy(10,7);
        printf("Enter Name : ");
//        gets(pwd.name);///???
        gets(pwd.name);
        gotoxy(10,8);
        printf("Enter Password : ");
        gets(pwd.password);

        fwrite(&pwd,sizeof(pwd),1,fp);
        gotoxy(10,15);
        printf("Want to add of another record?(y/n): ");
        fflush(stdin);
//        another = getch();///???
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue: ");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct password pwd;
    system("cls");
    gotoxy(10,3);
    printf("***** SAVED PASSWORDS *****");
    gotoxy(10,5);
    printf("S.No   Name              Password");
    gotoxy(10,6);
    printf("--------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&pwd,sizeof(pwd),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-18s%-8s",i,pwd.name,pwd.password);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue: ");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct password pwd;
    char stname[20];
    system("cls");
    gotoxy(10,3);
    printf("***** SEARCH A PASSWORD *****");
    gotoxy(10,5);
    printf("Enter name: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&pwd,sizeof(pwd),1,fp ) == 1){
        if(strcmp(stname,pwd.name) == 0){
            gotoxy(10,8);
            printf("Name : %s",pwd.name);
            gotoxy(10,9);
            printf("Password: %s",pwd.password);
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue: ");
    getch();
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    struct password pwd;
    system("cls");
    gotoxy(10,3);
    printf("***** CHANGE A PASSWORD *****");
    gotoxy(10,5);
    printf("Enter name: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&pwd,sizeof(pwd),1,fp) == 1)
    {
        if(strcmp(stname,pwd.name) == 0){
            gotoxy(10,8);
            printf("Enter new password: ");
            gets(pwd.password);

            fseek(fp ,-sizeof(pwd),SEEK_CUR);
            fwrite(&pwd,sizeof(pwd),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue: ");
    getch();
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct password pwd;
    system("cls");
    gotoxy(10,3);
    printf("***** DELETE A PASSWORD *****");
    gotoxy(10,5);
    printf("Enter name: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&pwd,sizeof(pwd),1,fp) == 1){
        if(strcmp(stname,pwd.name)!=0)
            fwrite(&pwd,sizeof(pwd),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue: ");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
