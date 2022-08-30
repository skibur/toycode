#include <string.h>

#define MAX 1024

void fencrypt(void);

void fencrypt(void)
{
	char buffer[MAX];
	int store;
	int len;
	char read;
	FILE *fpen;
	fpen = fopen("fencrypt.txt", "r");

	if(fpen != NULL)
	{
		printf("File fencrypt.txt opened.\n");
		store = 0;
		while(1)
		{
			read = fgetc(fpen);
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
	encrypt(buffer, len);
//	savefencrypt(buffer, len);
	printf("\n\n");
	fclose(fpen);
	}
	else
	{
		printf("Unable to open file.\n");
	}
}