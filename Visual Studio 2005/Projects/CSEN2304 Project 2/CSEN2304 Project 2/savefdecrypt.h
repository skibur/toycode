#include <stdlib.h>

char savefdecrypt(char *buffer_p, int len);

char savefdecrypt(char *buffer_p, int len)
{	
	int c;
	int option2;
	/* File pointer */
	FILE *savefdecrypt;

	for(;;)
	{
	printf("\n\nDo you want to save? (y or n) => ");
	/* reflush buffer */
	fflush(stdin);
	option2 = getchar();
	/* safety flush buffer */
	fflush(stdin);
	
	switch(option2)
	{
		case 'Y':
		case 'y':
			savefdecrypt = fopen("fdecryptmessage.txt", "w");

			if(savefdecrypt != NULL)
			{
				printf("File created: fdecryptmessage.txt");
				for(c = 0; c < len; c++)
				{   /* Copy decrypted message into fdecryptmessage.txt */
					fputc(buffer_p[c], savefdecrypt);
				}
				fclose(savefdecrypt);
				return 0;
			}
			return 0;
			break;
		case 'N':
		case 'n':
			return 0;
			break;
		default:
			printf("\nInvalid choice, Please select valid choice\n\n");
	}
	}
	return 0;
}