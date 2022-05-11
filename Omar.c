#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include666

struct pass {
    char username[50];
    int date, month, year;
    char pnumber[15];
    char NationalID[15];
	char AccountID[10];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
    char typeaccount[20];
};
 
struct money {
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};
 
struct userpass {
    char password[50];
};

void login(void)
{
    system("cls");
 
    char username[50];
    char password[50];
 
    int i, j, k;
    char ch;
    FILE *fp, *fu;
    struct pass u1;
    struct userpass u2;
 
    // Opening file of
    // user data
    fp = fopen("BankingData.txt",
               "rb");
 
    if (fp == NULL) {
        printf("ERROR IN OPENING FILE");
    }
    gotoxy(34, 2);
    printf(" ACCOUNT LOGIN ");
    gotoxy(7, 5);
    printf("***********************************************"
           "********************************");
 
    gotoxy(35, 10);
    printf("==== LOG IN ====");
 
    // Take input
    gotoxy(35, 12);
    printf("USERNAME.. ");
    scanf("%s", &username);
 
    gotoxy(35, 14);
    printf("PASSWORD..");
 
    // Input the password
    for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
 
        else
            break;
    }
 
    // Checking if username
    // exists in the file or not
    while (fread(&u1, sizeof(u1),
                 1, fp)) {
        if (strcmp(username,
                   u1.username)
            == 0) {
            loginsu();
            display(username);
        }
    }
 
    // Closing the file
    fclose(fp);
}

void loginsu(void)
{
    int i;
    FILE* fp;
    struct pass u1;
    system("cls");
    printf("Fetching account details.....\n");
    for (i = 0; i < 20000; i++) {
        i++;
        i--;
    }
 
    gotoxy(30, 10);
    printf("LOGIN SUCCESSFUL....");
    gotoxy(0, 20);
    printf("Press enter to continue");
 
    getch();
}

void account(void)
{
    char password[20];
    int passwordlength, i, seek = 0;
    char ch;
    FILE *fp, *fu;
    struct pass u1;
    struct userpass p1;
 
    struct userpass u2;
 
    // Opening file to
    // write data of a user
    fp = fopen("BankingData.txt", "ab");
 
    // Inputs
    system("cls");
    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");
 
   printf("\n\nFIRST NAME..");
    scanf("%s", &u1.fname);
 
    printf("\n\n\nLAST NAME..");
    scanf("%s", &u1.lname);
 
    printf("\n\nFATHER's NAME..");
    scanf("%s", &u1.fathname);
 
    printf("\n\nMOTHER's NAME..");
    scanf("%s", &u1.mothname);
 
    printf("\n\nADDRESS..");
    scanf("%s", &u1.address);
 
    printf("\n\nACCOUNT TYPE..");
    scanf("%s", &u1.typeaccount);
 
    printf("\n\nDATE OF BIRTH..");
    printf("\nDATE-");
    scanf("%d", &u1.date);
    printf("\nMONTH-");
    scanf("%d", &u1.month);
    printf("\nYEAR-");
    scanf("%d", &u1.year);
 
    printf("\n\nID NUMBER..");
    scanf("%s", u1.NationalID);
 
    printf("\n\nPHONE NUMBER..");
    scanf("%s", u1.pnumber);
 
    printf("\n\nID ACCOUNT.. ");
    scanf("%s", &u1.AccountID);
	
	printf("\n\nUSERNAME..");
    scanf("%s", &u1.username);
	
 
    printf("\n\nPASSWORD..");
 
    // Taking password in the form of
    // stars
    for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }
 
    // Writing to the file
    fwrite(&u1, sizeof(u1),
           1, fp);
 
    // Closing file
    fclose(fp);
 
    // Calling another function
    // after successful creation
    // of account
    accountcreated();
}

void accountcreated(void)
{
    int i;
    char ch;
    system("cls");
    printf(
        "PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
    for (i = 0; i < 200000000; i++) {
        i++;
        i--;
    }
 
    gotoxy(30, 10);
 
    printf("ACCOUNT CREATED SUCCESSFULLY....");
    gotoxy(0, 20);
 
    printf("Press enter to login");
 
    getch();
    login();
}
