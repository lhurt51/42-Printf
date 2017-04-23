#include "printf.h"
#include <stdio.h>

int main()
{
	printf("PRINTF: Hello%#Xtest\n", 42);
	ft_printf("FT_PRINTF: Hello%#X%%#Xtest\n", 42);
	return (1);
}
