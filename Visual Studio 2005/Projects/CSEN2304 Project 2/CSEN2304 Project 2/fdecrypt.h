#include <string.h>

#define MAX 1024

void fdecrypt(void);

void fdecrypt(void)
{
	char buffer[MAX];
	int store;
	int len;
	char read;
	FILE *fpde;
	fpde = fopen("fdecrypt.txt", "r");

	if(fpde != NULL)
	{
		printf("File fdecrypt.txt opened.\n");
		store = 0;
		while(1)
		{
			read = fgetc(fpde);
			if(read != EOF)
			{
				buffer[store] = read;
			}
			else 
			{break;}
			store++;
		}

	buffer[store]= '\0';
	len = strlen(buffer);
	decrypt(buffer, len);
//	savefdecrypt(buffer, len);
	printf("\n\n");
	fclose(fpde);
	}
	else
	{
		printf("Unable to open file.\n");
	}
}