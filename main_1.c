#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "src/ft_printf.h"

int main()
{
	const double RENT = 3453;
/*	printf("Origin :\n# = %#o, no = %o\n", 3453, 3453);	
	ft_printf("Ft :\n# = %#o, no = %o\n", 3453, 3453);	
	printf("Origin :\n# = %#O, no = %O\n", 3453, 3453);
	ft_printf("Ft :\n# = %#O, no = %O\n", 3453, 3453);
	printf("Origin :\n# = %#x, no = %x\n", 3453, 3453);
	ft_printf("Ft :\n# = %#x, no = %x\n", 3453, 3453);
	printf("Origin :\n# = %#X, no = %X\n", 3453, 3453);
	ft_printf("Ft :\n# = %#X, no = %X\n", 3453, 3453);*/


	printf("Origin 'f':  # = %#f, no = %f\n", RENT, RENT);
	ft_printf("Ft 'f':      # = %#f, no = %f\n", RENT, RENT);	
	printf("Origin 'F':  # = %#F, no = %F\n", RENT, RENT);
	ft_printf("Ft 'F':      # = %#F, no = %F\n", RENT, RENT);	
	printf("Origin 'g':  # = %#g, no = %g\n", RENT, RENT);
	ft_printf("Ft 'g':      # = %#g, no = %g\n", RENT, RENT);	
	printf("Origin 'G':  # = %#G, no = %G\n", RENT, RENT);
	ft_printf("Ft 'G':      # = %#G, no = %G\n", RENT, RENT);	
	printf("Origin 'e':  # = %#e, no = %e\n",RENT, RENT);
	ft_printf("Ft 'e':      # = %#e, no = %e\n", RENT, RENT);	
	printf("Origin 'E':  # = %#E, no = %E\n", RENT, RENT);
	ft_printf("Ft 'E':      # = %#E, no = %E\n", RENT, RENT);	
	printf("Origin 'a':  # = %#a, no = %a\n", RENT, RENT);
	ft_printf("Ft 'a':      # = %#a, no = %a\n", RENT, RENT);	
	printf("Origin 'A':  # = %#A, no = %A\n", RENT, RENT);
	ft_printf("Ft 'A':      # = %#A, no = %A\n", RENT, RENT);	

/*	printf("*%e*\n", RENT);
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
*/
	return 0;
}
