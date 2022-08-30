#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c, d, e;

	//use a space between each number.
	printf("Type in two numbers to use for adding, subtracting, multiplying and dividing: ");
	scanf("%d %d/n",&a, &b );

	__asm{

		//adding
			mov eax, a
			mov ebx, b
			add eax, ebx

			push eax

		//subtracting

			mov eax, a
			mov ebx, b
			sub eax, ebx

			push eax

		//multiplying

			mov eax, a
			mov ebx, b
			imul ebx

			push eax

		//dividing

			xor edx, edx
            
			mov eax, a
			mov ebx, b
			div ebx

			push eax
			push edx

			pop e
			pop d
			pop c
			pop b
			pop a


	}
	
	printf("your total value when adding:%d \n", a);
	printf("your total value when subtracting:%d \n", b);
	printf("your total value when multiplying:%d \n", c);
	printf("your value when dividing:%d  remainder:%d \n", d, e);



	return 0;

}
