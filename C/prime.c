//Program for Prime Number Generation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	int n, i = 1, j, c, col=0, row=10, ro=1;
	int pattern=0, /*currentprime=0,*/ previousprime=2,p=0;
	
	//clrscr();
	
	printf("Enter Number Of Terms\n");
	printf("Prime Numbers Are Follwing\n");
	scanf("%d",&n);
	
	while(i <= n)
	{
		
		c=0;
		for(j = 1; j <= i; j++)
		{
			if(i % j == 0)
			c++;
			
		}
		if(c == 2)
		{

						

			//printf("%d, ",i);
			col++;
			pattern = i - previousprime;
			printf("%d-%d, ", p,pattern);

			previousprime=i;
			p++;
			

		}

		i++;
		
		
		if (row == col) 
		{
			printf("   %d.\n", ro);
			col = 0;
			ro++;
		}
		
		
		
	}
	printf("\n");
	//getch();
}
