/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:36:13 by lhurt             #+#    #+#             */
/*   Updated: 2017/03/02 17:38:10 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

char	*str_low(char *str)
{
	int		i;

	i = ft_strlen(str);
	while (i-- > 0)
	{
		if (ft_isupper(str[i]))
			str[i] = ft_tolower(str[i]);
	}
	return (str);
}

int	check_case(va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (c == 'o' || c == 'O')
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned int), 8));
	else if (c == 'x')
		ft_putstr(str_low(ft_itoa_base(va_arg(ap, unsigned int), 16)));
	else if (c == 'X')
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned int), 16));
	else if (c == 'c')
		ft_putchar(va_arg(ap, int));
	else if (c == 's')
		ft_putstr(va_arg(ap, char *));
	else if (c == '%')
		ft_putchar(c);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!check_case(ap, *str))
				return (0);
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (1);
}

int main(void)
{
	int	test;

	test = (145 / 2.45);
	printf("Test %s with this %i with %c num1:%o num2:%X %% dec:%U\n", "hel\tlo", 2147483647, 'T', -1343400,  -13452, -2147483647);
	ft_printf("Test %s with this %i with %c num1:%o num2:%X %%\n", "hel\tlo", 2147483647, 'T', -1343400, -13452);
	return (0);
}
