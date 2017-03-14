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

int	printf_d(va_list ap, t_conv *obj)
{
	char	*tmp;

	tmp = ft_itoa_base(va_arg(ap, int), 10);
	if (obj->flags.plus && tmp[0] != '-')
		tmp = ft_strjoin("+", tmp);
	if (obj->flags.space && tmp[0] != '-')
		tmp = ft_strjoin(" ", tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_u(va_list ap, t_conv *obj)
{
	char	*tmp;

	tmp = ft_utoa_base(va_arg(ap, unsigned int), 10);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_o(va_list ap, t_conv *obj)
{
	char			*tmp;

	tmp = ft_utoa_base(va_arg(ap, unsigned int), 8);
	if (obj->flags.hash && tmp[0] != '0')
		tmp = ft_strjoin("0", tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_x(va_list ap, t_conv *obj)
{
	char			*tmp;

	tmp = str_low(ft_utoa_base(va_arg(ap, unsigned int), 16));
	if (obj->flags.hash && tmp[0] != '0')
		tmp = ft_strjoin("0x", tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_X(va_list ap, t_conv *obj)
{
	char			*tmp;

	tmp = ft_utoa_base(va_arg(ap, unsigned int), 16);
	if (obj->flags.hash && tmp[0] != '0')
		tmp = ft_strjoin("0X", tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_c(va_list ap, t_conv *obj)
{
	char			tmp;

	tmp = va_arg(ap, int);
	obj->size += 1;
	ft_putchar(tmp);
	return (obj->size);
}

int	printf_s(va_list ap, t_conv *obj)
{
	char			*tmp;

	tmp = va_arg(ap, char *);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	return (obj->size);
}

int	printf_per(t_conv *obj)
{
	char	*tmp;

	tmp = "%\0";
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	return (obj->size);
}

int	check_conv(va_list ap, t_conv *obj, char c)
{
	if (c == 'd' || c == 'i')
		return (printf_d(ap, obj));
	else if (c == 'u' || c == 'U')
		return (printf_u(ap, obj));
	else if (c == 'o' || c == 'O')
		return (printf_o(ap, obj));
	else if (c == 'x')
		return (printf_x(ap, obj));
	else if (c == 'X')
		return (printf_X(ap, obj));
	else if (c == 'c')
		return (printf_c(ap, obj));
	else if (c == 's')
		return (printf_s(ap, obj));
	else if (c == '%')
		return (printf_per(obj));
	else
		return (0);
}

int		check_flag(t_conv *obj, char c)
{
	if (c == '#')
		obj->flags.hash = 1;
	else if (c == '0')
		obj->flags.zero = 1;
	else if (c == '-')
		obj->flags.minus = 1;
	else if (c == '+')
		obj->flags.plus = 1;
	else if (c == ' ')
		obj->flags.space = 1;
	else
		return (0);
	return (1);
}

void	set_struct(t_conv *obj)
{
	obj->complete = 0;
	obj->size = 0;
	obj->flags.plus = 0;
	obj->flags.minus = 0;
	obj->flags.space = 0;
	obj->flags.hash = 0;
	obj->flags.zero = 0;
	obj->len.hh = 0;
	obj->len.h = 0;
	obj->len.l = 0;
	obj->len.ll = 0;
	obj->len.j = 0;
	obj->len.z = 0;
	obj->width = 0;
	obj->prec = 0;
}

int	check_all(va_list ap, t_conv *obj, const char *str, int *i)
{
	(*i)++;
	if (check_flag(obj, str[*i]))
		(*i)++;
	if (!check_conv(ap, obj, str[*i]))
		return (0);
	(*i)++;
	return (obj->size);
}

int	set_up_conv(va_list ap, const char *str, int *i)
{
	t_conv	*obj;
	int		tmp;

	obj = malloc(sizeof(t_conv));
	if (!obj)
		return (0);
	set_struct(obj);
	if (!check_all(ap, obj, str, i))
		return (0);
	tmp = obj->size;
	free(obj);
	return (tmp);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && !set_up_conv(ap, str, &i))
			return (0);
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (1);
}

int main(void)
{
	int	test;

	test = (145 / 2.45);
	printf("Test %s with this % d with %c num1:%#O num2:%X %% dec:%+d\n", "hel\tlo", -2147483647, 'T', 1230,  45630, -2147483647);
	ft_printf("Test %s with this % d with %c num1:%#O num2:%X %% dec:%+d\n", "hel\tlo", -2147483647, 'T', 1230, 45630, -2147483647);
	return (0);
}
