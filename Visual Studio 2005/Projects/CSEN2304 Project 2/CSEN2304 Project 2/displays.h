void title(void);
void help(void);
void encrypt_display(void);
void decrypt_display(void);
void fencrypt_display(void);
void fdecrypt_display(void);

void title(void)
{
	printf("+--------------------------------------------------+\n");
	printf("|       W e l c o m e   t o   E N D E  P R O       |\n");
	printf("+--------------------------------------------------+\n");
	printf("| A simple and very easy to use message encryption |\n");
	printf("| and decryption.  by Juan Antonio Sauceda 3/11/06 |\n");
	printf("+--------------------------------------------------+\n\n");
}

void help(void)
{
	printf("+--------------------------------------------------+\n");
	printf("|             H  E  L  P    M  E  N  U             |\n");
	printf("+--------------------------------------------------+\n");
	printf("| encrypt  -  converts plain text to cypher text   |\n");
	printf("| decrypt  -  converts cypher text to plain text   |\n");
	printf("| fencrypt -  encrypts a file (must be on folder)  |\n");
	printf("| fdecrypt -  decrypts a file (must be on folder)  |\n");
	printf("+--------------------------------------------------+\n\n");
}

void encrypt_display(void)
{
	printf("+--------------------------------------------------+\n");
	printf("|             E N C R Y P T   M E N U              |\n");
	printf("+--------------------------------------------------+\n\n");
}

void decrypt_display(void)
{
	printf("+--------------------------------------------------+\n");
	printf("|             D E C R Y P T   M E N U              |\n");
	printf("+--------------------------------------------------+\n\n");
}

void fencrypt_display(void)
{
	printf("+--------------------------------------------------+\n");
	printf("|        F I L E   E N C R Y P T   M E N U         |\n");
	printf("+--------------------------------------------------+\n\n");
}

void fdecrypt_display(void)
{
	printf("+--------------------------------------------------+\n");
	printf("|        F I L E   D E C R Y P T   M E N U         |\n");
	printf("+--------------------------------------------------+\n\n");
}