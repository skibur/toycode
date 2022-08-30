#include "savefencrypt.h"

#define MAX 1024

char encrypt(char *ep_plaintext, int len);

char encrypt(char *ep_plaintext, int len)
{
	int count;
	char encryptmessage[MAX];
	char *encryptmessage_p;

	encryptmessage_p = encryptmessage;

	for(count = 0; count < len ; count++)
	{
		/* Two switch function eliminate double letter */
		switch(*ep_plaintext)
		{
			case 'A':
			case 'a':
				encryptmessage[count] = 'J';
				break;
			case 'B':
			case 'b':
				encryptmessage[count] = 'M';
				break;
			case 'C':
			case 'c':
				encryptmessage[count] = 'P';
				break;
			case 'D':
			case 'd':
				encryptmessage[count] = 'H';
				break;
			case 'E':
			case 'e':
				encryptmessage[count] = 'U';
				break;
			case 'F':
			case 'f':
				encryptmessage[count] = 'Q';
				break;
			case 'G':
			case 'g':
				encryptmessage[count] = 'B';
				break;
			case 'H':
			case 'h':
				encryptmessage[count] = 'V';
				break;
			case 'I':
			case 'i':
				encryptmessage[count] = 'N';
				break;
			case 'J':
			case 'j':
				encryptmessage[count] = 'Y';
				break;
			case 'K':
			case 'k':
				encryptmessage[count] = 'I';
				break;
			case 'L':
			case 'l':
				encryptmessage[count] = 'R';
				break;
			case 'M':
			case 'm':
				encryptmessage[count] = 'E';
				break;
			case 'N':
			case 'n':
				encryptmessage[count] = 'W';
				break;
			case 'O':
			case 'o':
				encryptmessage[count] = 'L';
				break;
			case 'P':
			case 'p':
				encryptmessage[count] = 'Z';
				break;
			case 'Q':
			case 'q':
				encryptmessage[count] = 'X';
				break;
			case 'R':
			case 'r':
				encryptmessage[count] = 'T';
				break;
			case 'S':
			case 's':
				encryptmessage[count] = 'A';
				break;
			case 'T':
			case 't':
				encryptmessage[count] = 'O';
				break;
			case 'U':
			case 'u':
				encryptmessage[count] = 'G';
				break;
			case 'V':
			case 'v':
				encryptmessage[count] = 'K';
				break;
			case 'W':
			case 'w':
				encryptmessage[count] = 'D';
				break;
			case 'X':
			case 'x':
				encryptmessage[count] = 'C';
				break;
			case 'Y':
			case 'y':
				encryptmessage[count] = 'S';
				break;
			case 'Z':
			case 'z':
				encryptmessage[count] = 'F';
				break;
			case 32:
				//need random character function
				encryptmessage[count] = '9';
				break;
			default:
				encryptmessage[count] = 32;
				break;
		}
		ep_plaintext++;
		count++;

		switch(*ep_plaintext)
		{
			case 'J':
			case 'j':
				encryptmessage[count] = 'A';
				break;
			case 'M':
			case 'm':
				encryptmessage[count] = 'B';
				break;
			case 'P':
			case 'p':
				encryptmessage[count] = 'C';
				break;
			case 'H':
			case 'h':
				encryptmessage[count] = 'D';
				break;
			case 'U':
			case 'u':
				encryptmessage[count] = 'E';
				break;
			case 'Q':
			case 'q':
				encryptmessage[count] = 'F';
				break;
			case 'B':
			case 'b':
				encryptmessage[count] = 'G';
				break;
			case 'V':
			case 'v':
				encryptmessage[count] = 'H';
				break;
			case 'N':
			case 'n':
				encryptmessage[count] = 'I';
				break;
			case 'Y':
			case 'y':
				encryptmessage[count] = 'J';
				break;
			case 'I':
			case 'i':
				encryptmessage[count] = 'K';
				break;
			case 'R':
			case 'r':
				encryptmessage[count] = 'L';
				break;
			case 'E':
			case 'e':
				encryptmessage[count] = 'M';
				break;
			case 'W':
			case 'w':
				encryptmessage[count] = 'N';
				break;
			case 'L':
			case 'l':
				encryptmessage[count] = 'O';
				break;
			case 'Z':
			case 'z':
				encryptmessage[count] = 'P';
				break;
			case 'X':
			case 'x':
				encryptmessage[count] = 'Q';
				break;
			case 'T':
			case 't':
				encryptmessage[count] = 'R';
				break;
			case 'A':
			case 'a':
				encryptmessage[count] = 'S';
				break;
			case 'O':
			case 'o':
				encryptmessage[count] = 'T';
				break;
			case 'G':
			case 'g':
				encryptmessage[count] = 'U';
				break;
			case 'K':
			case 'k':
				encryptmessage[count] = 'V';
				break;
			case 'D':
			case 'd':
				encryptmessage[count] = 'W';
				break;
			case 'C':
			case 'c':
				encryptmessage[count] = 'X';
				break;
			case 'S':
			case 's':
				encryptmessage[count] = 'Y';
				break;
			case 'F':
			case 'f':
				encryptmessage[count] = 'Z';
				break;
			case 32:
				//need random character function
				encryptmessage[count] = '3';
				break;
			default:
				encryptmessage[count] = 32;
				break;
		}
		ep_plaintext++;
	}
	encryptmessage[count] = '\0';
	printf("%s", encryptmessage);
	savefencrypt(encryptmessage_p, len);
	return 0;
}