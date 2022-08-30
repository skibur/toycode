#include <stdio.h>
#include <stdlib.h>

unsigned int FCFS(unsigned int PROC[], unsigned int EXE[], unsigned int AT[]);

int main(void)
{
	unsigned int PROC[6] = {1,2,3,4,5,6};
	unsigned int  EXE[6] = {3,4,1,2,6,5};
	unsigned int   AT[6] = {0,0,2,3,2,1};
	
	FCFS(PROC, EXE, AT);

	return 0;
}

unsigned int FCFS(unsigned int PROC[], unsigned int EXE[], unsigned int AT[])
{
	int x;
	unsigned int   ARRAY_ONE[3];
	unsigned int   ARRAY_TWO[3];
	unsigned int ARRAY_THREE[3];
	unsigned int  ARRAY_FOUR[3];
	unsigned int  ARRAY_FIVE[3];
	unsigned int   ARRAY_SIX[3];

	unsigned int *p_array_one;
	unsigned int *p_array_two;

	p_array_one = ARRAY_ONE;
	p_array_two = ARRAY_TWO;
	
	ARRAY_ONE[0]   = PROC[0];
	ARRAY_ONE[1]   =  EXE[0];
	ARRAY_ONE[2]   =   AT[0];

	ARRAY_TWO[0]   = PROC[1];
	ARRAY_TWO[1]   =  EXE[1];
	ARRAY_TWO[2]   =   AT[1];

	ARRAY_THREE[0] = PROC[2];
	ARRAY_THREE[1] =  EXE[2];
	ARRAY_THREE[2] =   AT[2];
	
	ARRAY_FOUR[0]  = PROC[3];
	ARRAY_FOUR[1]  =  EXE[3];
	ARRAY_FOUR[2]  =   AT[3];
	
	ARRAY_FIVE[0]  = PROC[4];
	ARRAY_FIVE[1]  =  EXE[4];
	ARRAY_FIVE[2]  =   AT[4];

	ARRAY_SIX[0]   = PROC[5];
	ARRAY_SIX[1]   =  EXE[5];
	ARRAY_SIX[2]   =   AT[5];

	printf("               PROC\tEXE\t AT\t\n");
	printf("Array ONE   is ");
	for (x = 0; x < 3; x++)
	{
		printf(" %d\t", ARRAY_ONE[x]);
	}
	printf("\n");

	printf("Array TWO   is ");
	for (x = 0; x < 3; x++)
	{
		printf(" %d\t", ARRAY_TWO[x]);
	}
	printf("\n");

	printf("Array THREE is ");
	for (x = 0; x < 3; x++)
	{
		printf(" %d\t", ARRAY_THREE[x]);
	}
	printf("\n");

	printf("Array FOUR  is ");
	for (x = 0; x < 3; x++)
	{
		printf(" %d\t", ARRAY_FOUR[x]);
	}
	printf("\n");

	printf("Array FIVE  is ");
	for (x = 0; x < 3; x++)
	{
		printf(" %d\t", ARRAY_FIVE[x]);
	}
	printf("\n");

	printf("Array SIX   is ");
	for (x = 0; x < 3; x++)
	{
		printf(" %d\t", ARRAY_SIX[x]);
	}
	printf("\n\n");

		/*printf("Array One is %d\n",   ARRAY_TWO[x]);
		printf("Array One is %d\n", ARRAY_THREE[x]);
		printf("Array One is %d\n",  ARRAY_FOUR[x]);
		printf("Array One is %d\n",  ARRAY_FIVE[x]);
		printf("Array One is %d\n",   ARRAY_SIX[x]);*/



/***********************************************************/
	x = 2;

	//FOR LOOP
    p_array_one[x];
	p_array_two[x];

	if(p_array_one[x] == p_array_two[x])
	{
		x = x - 2;
		p_array_one[x];
		p_array_two[x];
		
		if(p_array_one[x] < p_array_two[x])
		   {printf("%d ", *p_array_one);
			printf("%d ", *p_array_two);}
		else 
		   {printf("%d ", *p_array_two);
			printf("%d ", *p_array_one);}
	}
	else if(p_array_one[x] < p_array_two[x])
	   {
		x = x - 2;
		printf("%d ", *p_array_one);
		printf("%d ", *p_array_two);}
	else
	   {
	    x = x - 2;
		printf("%d ", *p_array_two);
		printf("%d ", *p_array_one);}
/*****************************************************************/

	for (x = 0; x < 6; x++)
	{
		if(AT[x] == 1)


	printf("\n\n");

	return 0;
}