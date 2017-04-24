#include "printf.h"
#include <stdio.h>

int main()
{
	// wchar_t *str = L"Hello";

	// printf("PRINTF: Hello%-10lctest %ls *Kashim a � histoires à raconterIl fait au moins ��c\n", (wchar_t)0, str);
	// ft_printf("FT_PRINTF: Hello%-10lctest %ls *Kashim a � histoires à raconterIl fait au moins ��c\n", (wchar_t)0, str);
	ft_printf("%c\n", 42);
	ft_printf("Kashim a %c histoires à raconter\n", 1001);
	ft_printf("Il fait au moins %c\n", -8000);
	ft_printf("%c\n", -0);
	ft_printf("%c\n", 0);
	// ft_printf("%c\n", INT_MAX);
	ft_printf("%c\n", 'c');
	ft_printf("%c\n", '\n');
	ft_printf("%c\n", 'l');
	ft_printf("%c\n", 'y');
	ft_printf("%c\n", ' ');
	ft_printf("%c\n", 'e');
	ft_printf("%c\n", 's');
	ft_printf("%c\n", 't');
	ft_printf("%c\n", ' ');
	ft_printf("%c\n", 'f');
	ft_printf("%c\n", 'a');
	ft_printf("%c\n", 'n');
	ft_printf("%c\n", 't');
	ft_printf("%c\n", 'a');
	ft_printf("%c\n", 's');
	ft_printf("%c\n", 't');
	ft_printf("%c\n", 'i');
	ft_printf("%c\n", 'q');
	ft_printf("%c\n", 'u');
	ft_printf("%c\n", 'e');
	ft_printf("%c\n", '!');
	ft_printf("%c\n", '\r');
	ft_printf("%c\n", '\t');
	return (1);
}
