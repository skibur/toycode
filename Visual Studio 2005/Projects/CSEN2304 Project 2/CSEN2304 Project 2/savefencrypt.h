#include <stdlib.h>

char savefencrypt(char *buffer_p, int len);

char savefencrypt(char *buffer_p, int len)
{	
	int c;
	int option2;

	/* File pointer */
	FILE *savefencrypt;

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
			savefencrypt = fopen("fencryptmessage.txt", "w");

			if(savefencrypt != NULL)
			{
				printf("File created: fencryptmessage.txt");
				for(c = 0; c < len; c++)
				{   /* Copy encrypted message into fencryptmessgae.txt.*/
					fputc(buffer_p[c], savefencrypt);
				}
				fclose(savefencrypt);
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