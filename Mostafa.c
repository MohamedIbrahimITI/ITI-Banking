#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void ReturnMenu(void)
{
	system("cls");
	int i, a, b, choice;
    int passwordlength;
 
    gotoxy(20, 3);
 
    // Creating a Main
    // menu for the user
    printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
    gotoxy(18, 5);
 
    printf("**********************************");
    gotoxy(25, 7);
 
    printf("\n\nDEVELOPER Omar Shaheen - Mostafa Ali - Mohamed Ibrahim ....");
 
    gotoxy(20, 12);
    printf("1.... CREATE A BANK ACCOUNT");
 
    gotoxy(20, 14);
    printf("2.... ALREADY A USER? SIGN IN");
    gotoxy(20, 16);
    printf("3.... EXIT\n\n");
 
    printf("\n\nENTER YOUR CHOICE..");
 
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        system("cls");
        printf("\n\n USERNAME 50 CHARACTERS MAX!!");
        printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
        account();
        break;
 
    case 2:
        login();
        break;
 
    case 3:
        exit(0);
        break;
 
        getch();
    }
		
}

void logout(void)
{
    int i, j;
    system("cls");
    printf("please wait, logging out");
 
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 25000000; j++) {
            i++;
            i--;
        }
        printf(".");
    }
 
    gotoxy(30, 10);
    printf("Sign out successfully..\n");
 
    gotoxy(0, 20);
    printf("press any key to continue..");
 
    getch();
}