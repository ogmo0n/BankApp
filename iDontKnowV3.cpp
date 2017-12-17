// iDontKnowV3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define WIDTH 74
#define SIZE 60 //size of char array for username

// function declarations
void add_acct(char nombre[], double *savingsPtr);
void deposit(double *savingsPtr, double *checkingPtr);
void withdrawal(double *savingsPtr, double *checkingPtr);
void funds_transfer(double *savingsPtr, double *checkingPtr);
void acct_info(char nombre[], double *savingsPtr, double *checkingPtr);
void trans_hist();
int clean_input();
void leave();
void char_bar();
void space_line();


int main(void) {

	int input = 0;
	int randomVar = 1; // change to char and compare as char ?
	double savingsBalance = 0;
	double checkingBalance = 0;
	char nombre[SIZE] = "Current User";

	while (randomVar == 1) {

		system("cls");
		
		// character box for menu border
		puts("");
		char_bar();
		puts("");
		space_line();
		puts(" *\t\t\t\t~ Menu ~\t\t\t\t   *");
		space_line();
		puts(" *\t 1. Create New Account\t\t\t\t\t\t   *");
		puts(" *\t 2. Cash Deposit\t\t\t\t\t\t   *");
		puts(" *\t 3. Cash Withdrawal\t\t\t\t\t\t   *");
		puts(" *\t 4. Fund Transfer\t\t\t\t\t\t   *");
		puts(" *\t 5. Account Information\t\t\t\t\t\t   *");
		puts(" *\t 6. Transaction Information\t\t\t\t\t   *");
		puts(" *\t 7. Exit\t\t\t\t\t\t\t   *");
		space_line();
		puts(" *\t\t Press a choice between the range [1-7]\t\t\t   *");
		space_line();
		char_bar();
		printf_s("%s", "\n\n\t");
		scanf_s("%d", &input);
	// check user input 
		if (input == 1) {
			add_acct(nombre, &savingsBalance);
		} else if (input == 2) {
			deposit(&savingsBalance, &checkingBalance);
		} else if (input == 3) {
			withdrawal(&savingsBalance, &checkingBalance);
		} else if (input == 4) {
			funds_transfer(&savingsBalance, &checkingBalance);
		} else if (input == 5) {
			acct_info(nombre, &savingsBalance, &checkingBalance);
		} else if (input == 6) {
			trans_hist();
		} else if (input == 7) { /////*********** CLEAN INPUT HERE ************/////
			leave();
		} else {
			puts("\n\tYour input is not in range! Please press ENTER, then \n\tenter a number between 1 and 7\n");
			_getch();
			//main(); //this is in other code
		}
	}
	return 0;
}

void add_acct(char nombre[], double *savingsPtr) {
	system("cls");

	int flag;
	char c;
	double newBalance = 0;
	char name[SIZE];

	puts("");
	puts("\t\t\t* Add New Account *");
	puts("");
	printf_s("Please enter the legal name to be used on your account (limit of %d chars)", SIZE);
	puts("\n");
	getchar();
	fgets(name, SIZE, stdin);
	name[strlen(name) - 1] = '\0';
	strcpy_s(nombre, SIZE, name);
	puts("");
	printf_s("We are opening a new savings account for Customer: %s", name);
	puts("\n");
	puts("How much money would you like to add to open this account?");
	puts("");
	printf_s("%s", "$");
	flag = scanf_s("%lf%c", &newBalance, &c);
	while (1) {
		while (flag != 2 || c != '\n') {
			clean_input();
			puts("");
			puts("Please enter a number for starting balance");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &newBalance, &c);
		}	
		if (newBalance < 0) {
			puts("");
			puts("You may not open an account with a negative balance\n"
				 "You're welcome. Try again.");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &newBalance, &c);
		} else {
			*savingsPtr = *savingsPtr + newBalance;
			break;
		}
	}
	puts("");
	printf_s("Your new savings account balance is $%.2lf", *savingsPtr);
	puts("");
	printf_s("%s", "\nPress any key to continue...");
	_getch(); 

}

void deposit(double *savingsPtr, double *checkingPtr) {

	system("cls");

	double savingsDeposit = 0;
	double checkingDeposit = 0;
	char c; // holds last char of user input
	int flag; // holds scanf's return value

	puts("");
	puts("\t\t\t* Process a Cash Deposit *");
	puts("");
	printf_s("The current savings account balance is: $%.2lf", *savingsPtr);
	puts("");
	printf_s("The current checking account balance is: $%.2lf", *checkingPtr);
	puts("\n");
	puts("Enter the amount to deposit into savings");
	puts("");
	printf_s("%s", "$");
	flag = scanf_s("%lf%c", &savingsDeposit, &c);
	while (1) {
		while (flag != 2 || c != '\n') {
			clean_input();
			puts("");
			puts("Please enter a number for deposit amount");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &savingsDeposit, &c);
		}	
		if (savingsDeposit < 0) {
			puts("");
			puts("You may not deposit a negative value\n"
				 "Please enter the amount to be deposited");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &savingsDeposit, &c);
		} else {
			*savingsPtr = *savingsPtr + savingsDeposit;
			break;
		}
	}
	puts("");
	puts("Enter the amount to deposit into checking");
	puts("");
	printf_s("%s", "$");
	flag = scanf_s("%lf%c", &checkingDeposit, &c);

	while (1) {
		while (flag != 2 || c != '\n') {
			clean_input();
			puts("");
			puts("Please enter a number for deposit amount");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &checkingDeposit, &c);
		}	
		if (checkingDeposit < 0) {
			puts("");
			puts("You may not deposit a negative value\n"
				 "Please enter the amount to be deposited");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &checkingDeposit, &c);
		} else {
			*checkingPtr = *checkingPtr + checkingDeposit;
			break;
		}
	}
	puts("");
	printf_s("The new savings account balance is: $%.2lf", *savingsPtr);
	puts("\n");
	printf_s("The new checking account balance is: $%.2lf", *checkingPtr);
	puts("\n");
	printf_s("%s", "Press any key to continue...");
	_getch();
}

void withdrawal(double *savingsPtr, double *checkingPtr) { 

	system("cls");

	double savingsWithdrawal = 0;
	double checkingWithdrawal = 0;
	int flag;
	char c;

	puts("");
	puts("\t\t\t* Process a Cash Withdrawal *");
	puts("");
	printf_s("The current savings account balance is: $%.2lf", *savingsPtr);
	puts("");
	printf_s("The current checking account balance is: $%.2lf", *checkingPtr);
	puts("\n");
	puts("Enter the amount to be withdrawn from savings");
	puts("");
	printf_s("%s", "$");
	flag = scanf_s("%lf%c", &savingsWithdrawal, &c);
	while(1) {	
		while (flag != 2 || c != '\n') {
			clean_input();
			puts("");
			puts("Please enter a number for the withdrawal amount");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &savingsWithdrawal, &c);
		}
		if (savingsWithdrawal < 0) {
			puts("");
			puts("You may not withdrawal a negative value\n"
					"Please enter the amount to be withdrawn");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &savingsWithdrawal, &c);
		} else if (savingsWithdrawal > *savingsPtr) { // overdraft protection
			puts("");
			puts("You may not withdrawal more money than you possess\n"
					"Please enter the amount to be withdrawn");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &savingsWithdrawal, &c);
		} else {
			*savingsPtr = *savingsPtr - savingsWithdrawal;
			break;
		}
	}
	puts("");
	puts("Enter the amount to be withdrawn from checking");
	puts("");
	printf_s("%s", "$");
	flag = scanf_s("%lf%c", &checkingWithdrawal, &c);
	while(1) {	
		while (flag != 2 || c != '\n') {
			clean_input();
			puts("");
			puts("Please enter a number for the withdrawal amount");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &checkingWithdrawal, &c);
		}
		if (checkingWithdrawal < 0) {
			puts("");
			puts("You may not withdrawal a negative value\n"
					"Please enter the amount to be withdrawn");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &checkingWithdrawal, &c);
		} else if (checkingWithdrawal > *checkingPtr) { // overdraft protection
			puts("");
			puts("You may not withdrawal more money than you possess\n"
					"Please enter the amount to be withdrawn");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &checkingWithdrawal, &c);
		} else {
			*checkingPtr = *checkingPtr - checkingWithdrawal;
			break;
		}
	}
	puts("");
	printf_s("Your new savings account balance is: $%.2lf", *savingsPtr);
	puts("\n");
	printf_s("Your new checking account balance is: $%.2lf", *checkingPtr);
	puts("\n");
	printf_s("%s", "Press any key to continue...");
	_getch();
}

void funds_transfer(double *savingsPtr, double *checkingPtr) { 

	system("cls");

	double s2cTransfer = 0; // make this amount not exceed total in account
	double c2sTransfer = 0;
	int flag;
	char c;

	puts("");
	puts("\t\t* Transfer Funds from Savings to Checking *");
	puts("");
	
	printf_s("The current savings account balance is: $%.2lf", *savingsPtr);
	puts("");
	printf_s("The current checking account balance is: $%.2lf", *checkingPtr);
	/*
	printf_s("Transfer funds from checking to savings? (Y/N)");
	scanf_s(" %c", &ch, 1); 
	if (ch == 'y' || ch == 'Y') {
		//code for checking to savings transfer
	} else if (ch == 'n' || ch == 'N') {
		printf_s("Would you like to transfer funds from savings to checking? (Y/N)");
		// code for savings to checking transfer
	} else {
		// code for else
	}
	*/
	puts("\n");
	puts("Enter the amount to be transferred from savings to checking");
	puts("");
	printf_s("%s", "$");
	flag = scanf_s("%lf%c", &s2cTransfer, &c);
	while (1) {
		while (flag != 2 || c != '\n') {
			clean_input();
			puts("");
			puts("Please enter a number for the transfer amount");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &s2cTransfer, &c);
		}
		if (s2cTransfer < 0) {
			puts("");
			puts("You may not transfer a negative value\n"
				 "Please enter the amount to be transferred");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &s2cTransfer, &c);
		} else if (s2cTransfer > *savingsPtr) { 
			puts("");
			puts("You may not transfer more money than you possess\n"
				 "Please enter the amount to be transferred");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &s2cTransfer, &c);
		} else {
			*savingsPtr = *savingsPtr - s2cTransfer;
			*checkingPtr = *checkingPtr + s2cTransfer;
			break;
		}
	}
	puts("");
	puts("Enter the amount to be transferred from checking to savings");
	puts("");
	printf_s("%s", "$");
	flag = scanf_s("%lf%c", &c2sTransfer, &c);
	while (1) {
		while (flag != 2 || c != '\n') {
			clean_input();
			puts("");
			puts("Please enter a number for the transfer amount");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &c2sTransfer, &c);
		}
		if (c2sTransfer < 0) {
			puts("");
			puts("You may not transfer a negative value\n"
				 "Please enter the amount to be transferred");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &c2sTransfer, &c);
		} else if (c2sTransfer > *checkingPtr) { 
			puts("");
			puts("You may not transfer more money than you possess\n"
				 "Please enter the amount to be transferred");
			puts("");
			printf_s("%s", "$");
			flag = scanf_s("%lf%c", &c2sTransfer, &c);
		} else {
			*savingsPtr = *savingsPtr + c2sTransfer;
			*checkingPtr = *checkingPtr - c2sTransfer;
			break;
		}
	}
	puts("");
	printf_s("The new savings account balance is: $%.2lf", *savingsPtr);
	puts("\n");
	printf_s("The new checking account balance is: $%.2lf", *checkingPtr);
	puts("\n");
	printf_s("%s", "Press any key to continue...");
	_getch();
}

void acct_info(char nombre[], double *savingsPtr, double *checkingPtr) {

	system("cls");
	puts("");
	printf_s("\t\t* Current Account Balances for %s *", nombre);
	puts("\n");
	printf_s("The current Savings Account Balance is: $%.2lf", *savingsPtr);
	puts("");
	printf_s("The current Checking Account Balance is: $%.2lf", *checkingPtr);
	puts("\n");
	printf_s("Press any key to continue...");
	_getch();
}

void trans_hist(void) {

	system("cls");
	puts("");
	puts("There is no transaction history available at this time");
	puts("");
	printf_s("%s", "Press any key to continue...");
	_getch();
}

int clean_input(void) {
	while (getchar() != '\n'); 
	return 1;
}

void leave(void) {
	char d;
	int randomVar = 1;

	system("cls");

	while (randomVar == 1) {
		puts("");
		printf_s("%s", "Exit? (Y/N): ");
		scanf_s(" %c", &d, 1); // the third parameter is the only way char worked
		puts("");
		if (d == 'Y' || d == 'y') {
			exit(0);
		} else if (d == 'N' || d == 'n') {
			break; 
		} else {
			puts("");
			puts("Please enter 'Y' or 'N'");
		} 
	}
}

void char_bar(void) {
	printf_s("%c", ' ');
	for (int i = 0; i <= (WIDTH)/2; i++) {
		printf_s("%s", "* ");
	}
}

void space_line(void) {
	printf_s("%s", " *");
	for (int i = 0; i < 73; i++) {
		printf_s("%c", ' ');
	}
	puts("*");

}