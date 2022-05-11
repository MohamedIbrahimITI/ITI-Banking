#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct money {
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};

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
 
void checkbalance(char username2[])
{
    system("cls");
    FILE* fm;
    struct money m1;
    char ch;
    int i = 1, summoney = 0;
 
    // Opening amount file record
    fm = fopen("TransferingData.txt", "rb");
 
    int k = 5, l = 10;
    int m = 30, n = 10;
    int u = 60, v = 10;
 
    gotoxy(30, 2);
    printf("==== BALANCE DASHBOARD ====");
    gotoxy(30, 3);
    printf("***************************");
    gotoxy(k, l);
    printf("S no.");
    gotoxy(m, n);
    printf("TRANSACTION ID");
    gotoxy(u, v);
    printf("AMOUNT");
 
    // Reading username to
    // fetch the correct record
    while (fread(&m1, sizeof(m1),
                 1, fm)) {
        if (strcmp(username2,
                   m1.usernameto)
            == 0) {
            gotoxy(k, ++l);
            printf("%d", i);
            i++;
            gotoxy(m, ++n);
            printf("%s", m1.userpersonfrom);
 
            gotoxy(u, ++v);
            printf("%d", m1.money1);
            // Adding and
            // finding total money
            summoney = summoney + m1.money1;
        }
    }
 
    gotoxy(80, 10);
    printf("TOTAL AMOUNT");
 
    gotoxy(80, 12);
    printf("%d", summoney);
 
    getch();
 
    // Closing file after
    // reading it
    fclose(fm);
    display(username2);
}

void transfermoney(void)
{
    int i, j;
    FILE *fm, *fp;
    struct pass u1;
    struct money m1;
    char usernamet[20];
    char usernamep[20];
    system("cls");
 
    // Opening file in read mode to
    // read user's username
    fp = fopen("BankingData.txt", "rb");
 
    // Creating a another file
    // to write amount along with
    // username to which amount
    // is going to be transferred
    fm = fopen("TransferingData.txt", "ab");
 
    gotoxy(33, 4);
    printf("---- TRANSFER MONEY ----");
    gotoxy(33, 5);
    printf("========================");
 
    gotoxy(33, 11);
    printf("FROM (your username).. ");
    scanf("%s", &usernamet);
 
    gotoxy(33, 13);
    printf(" TO (username of person)..");
    scanf("%s", &usernamep);
 
    // Checking for username if it
    // is present in file or not
    while (fread(&u1, sizeof(u1),
                 1, fp))
 
    {
        if (strcmp(usernamep,
                   u1.username)
            == 0) {
            strcpy(m1.usernameto,
                   u1.username);
            strcpy(m1.userpersonfrom,
                   usernamet);
        }
    }
    gotoxy(33, 16);
 
    // Taking amount input
    printf("ENTER THE AMOUNT TO BE TRANSFERRED..");
    scanf("%d", &m1.money1);
 
    // Writing to the file
    fwrite(&m1, sizeof(m1),
           1, fm);
 
    gotoxy(0, 26);
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");
 
    gotoxy(0, 28);
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");
 
    gotoxy(0, 29);
    printf("transfering amount, Please wait..");
 
    gotoxy(10, 27);
    for (i = 0; i < 70; i++) {
        for (j = 0; j < 1200000; j++) {
            j++;
            j--;
        }
        printf("*");
    }
 
    gotoxy(33, 40);
    printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
    getch();
 
    // Close the files
    fclose(fp);
    fclose(fm);
 
    // Function to return
    // to the home screen
    display(usernamet);
}

void display(char username1[])
{
 system("cls");
    FILE* fp;
    int choice, i;
    fp = fopen("BankingData.txt", "rb");
    struct pass u1;
 
    if (fp == NULL) {
        printf("error in opening file");
    }
 
    while (fread(&u1, sizeof(u1),
                 1, fp)) {
        if (strcmp(username1,
                   u1.username)
            == 0) {
            gotoxy(30, 1);
            printf("WELCOME, %s %s",
                   u1.fname, u1.lname);
            gotoxy(28, 2);
            printf("..........................");
            gotoxy(55, 6);
            printf("==== YOUR ACCOUNT INFO ====");
            gotoxy(55, 8);
            printf("***************************");
            gotoxy(55, 10);
            printf("NAME..%s %s", u1.fname,
                   u1.lname);
 
            gotoxy(55, 12);
            printf("FATHER's NAME..%s %s",
                   u1.fathname,
                   u1.lname);
 
            gotoxy(55, 14);
            printf("MOTHER's NAME..%s",
                   u1.mothname);
 
            gotoxy(55, 16);
            printf("NATIONAL ID..%s",
                   u1.NationalID);
 
            gotoxy(55, 18);
            printf("MOBILE NUMBER..%s",
                   u1.pnumber);
 
            gotoxy(55, 20);
            printf("DATE OF BIRTH.. %d-%d-%d",
                   u1.date, u1.month, u1.year);
 
            gotoxy(55, 22);
            printf("ADDRESS..%s", u1.address);
 
            gotoxy(55, 24);
            printf("ACCOUNT TYPE..%s",
                   u1.typeaccount);
				   
		    gotoxy(55, 26);
            printf("ACCOUNT ID..%s",
                   u1.AccountID);
        }
    }
 
    fclose(fp);
 
    gotoxy(0, 6);
 
    // Menu to perform different
    // actions by user
    printf(" HOME ");
    gotoxy(0, 7);
    printf("******");
    gotoxy(0, 9);
    printf(" 1....CHECK BALANCE");
    gotoxy(0, 11);
    printf(" 2....TRANSFER MONEY");
    gotoxy(0, 13);
    printf(" 3....LOG OUT\n\n");
    
	gotoxy(0, 15);
    printf(" 4....RETURNMEUM\n\n");
	
	gotoxy(0, 17);
    printf(" 5....EXIT\n\n");
 
    printf(" ENTER YOUR CHOICES..");
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        checkbalance(username1);
        break;
 
    case 2:
        transfermoney();
        break;
 
    case 3:
        logout();
        login();
        break;
	
	case 4:
		
		ReturnMenu();
		break;
		
 
    case 5:
        exit(0);
        break;
    }
}