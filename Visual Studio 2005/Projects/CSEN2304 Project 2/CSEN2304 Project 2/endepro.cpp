#include "stdafx.h"          // Standard windows header file
#include "decrypt.h"         // Decrypts a message or text
#include "fdecrypt.h"        // Decrypts a file
#include "encrypt.h"         // Encrypts a messages or text
#include "fencrypt.h"        // Encrypts a file
#include "displays.h"        // Displays options by banners
#include "userinput.h"       // Userinput to determine direction
#include <string.h>          // strlen()
#include <stdlib.h>          // system()

int check_option(int option);

int main(void)
{
	int option;
	
	/* This function uses the built-in commmand to clear the screen.*/
//	system("cls");

	/* Displays the Usage of the Program.*/
	title();
	
	for(;;)
	{
		/* The Main Menu of ENDEPRO.*/
		printf("1. encryption\n");
		printf("2. decryption\n");
		printf("3. fencrypt\n");
		printf("4. fdecrypt\n");
		printf("5. help\n");
		printf("6. exit\n");
		printf("\nPlease enter option => ");
		
		/* get option and assign it to option.*/
		option = getchar();

		/* fflush() clears the buffer's extra charactors.*/
		fflush(stdin);
		check_option(option);
	}
}

/* Fucntion to determine the flow of the program's execution.*/
int check_option(int option)
{
	int choice;

	switch(option)
	{
		case '1':
			choice = 1;
		//	system("cls");
			encrypt_display();
			userinput(choice);
			break;
		case '2':
			choice = 2;
		//	system("cls");
			decrypt_display();
			userinput(choice);
			break;
		case '3':
		//	system("cls");
			fencrypt_display();
			fencrypt();
			break;
		case '4':
		//	system("cls");
			fdecrypt_display();
			fdecrypt();
			break;
		case '5':
		//	system("cls");
			help();
			break;
		case '6':
			exit(0);
		default:
			printf("\nInvalid choice, Please select valid choice\n\n");
	}
	return (option);
}