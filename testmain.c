#include "printf.h"
#include <stdio.h>

int main()
{
	printf("PRINTF: Hello%-10ctest\n", 'T');
	ft_printf("FT_PRINTF: Hello%-10ctest\n", 'T');
	return (1);
}
