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

int	check_case(va_list ap, char c)
{
	int		d;
	char	*tmp;

	if (c == 'd')
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
	}
	else if (c == 's')
	{
		tmp = va_arg(ap, char *);
		ft_putstr(tmp);
	}
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
			check_case(ap, *str);
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
	printf("Test %s with this %d\n", "hel\tlo", 15);
	ft_printf("Test %s with this %d\n", "hel\tlo", 15);
	return (0);
}
