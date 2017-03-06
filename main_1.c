#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

int main()
{
	const double RENT = 3;
	printf("*%#a*\n", RENT);	
	printf("*%e*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3E*\n", RENT);
	printf("*%+5.2f*\n", RENT);

	printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**% d% d **\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
	printf("\n");

	printf ("%zu\n %zu\n", sizeof(int64_t), sizeof(intmax_t)); 

	return 0;
}
