#include <stdlib.h>
#include <string.h>

/* MAX 1024 charactors. Change if needed.*/
#define MAX 1024

int userinput(int choice);

int userinput(int choice)
{
	int len = 0;

	/* plaintext hold users message or text.*/
	char plaintext[MAX];

	/* Pointer to modify the message or text.*/ 
	char *ep_plaintext;
	
	/* assigning pointer to plaintext.*/
	ep_plaintext = plaintext;
	
	printf("\nPlease enter Message => ");
	fgets(plaintext, MAX-1, stdin);

	/* determine the size of text.*/
	len = strlen(plaintext);
	printf("\n");
	
	if(choice == 1)
		/* Encrypt message and loop by size of message.*/
		{encrypt(ep_plaintext, len);}
	else
		/* Decrypt message and loop by size of message.*/
		{decrypt(ep_plaintext, len);}

	printf("\n\n");
	return 0;
}