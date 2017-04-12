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

char *modify_width(t_conv *obj, char *str)
{
	unsigned int 	len;
	char			*space;

	len = ft_strlen(str);
	if (obj->flags.zero && !obj->b_prec)
		space = ft_strdup("0");
	else
		space = ft_strdup(" ");
	if (len < obj->width)
	{
		if (obj->flags.minus)
		{
			str = ft_strjoin(str, space);
			while (++len < obj->width)
				str = ft_strjoin(str, space);
		}
		else
		{
			str = ft_strjoin(space, str);
			while (++len < obj->width)
				str = ft_strjoin(space, str);
		}
	}
	ft_strdel(&space);
	return (str);
}

char *modify_prec(t_conv *obj, char *str)
{
	unsigned int 	len;
	char			*ext;

	len = ft_strlen(str);
	ext = ft_strdup("0");
	if (len < obj->prec)
	{
		str = ft_strjoin(ext, str);
		while (++len < obj->prec)
			str = ft_strjoin(ext, str);
	}
	ft_strdel(&ext);
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
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_D(va_list ap, t_conv *obj)
{
	char	*tmp;

	tmp = ft_ltoa_base(va_arg(ap, long), 10);
	if (obj->flags.plus && tmp[0] != '-')
		tmp = ft_strjoin("+", tmp);
	if (obj->flags.space && tmp[0] != '-')
		tmp = ft_strjoin(" ", tmp);
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_u(va_list ap, t_conv *obj)
{
	char	*tmp;

	tmp = ft_utoa_base(va_arg(ap, unsigned int), 10);
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_U(va_list ap, t_conv *obj)
{
	char	*tmp;

	tmp = ft_ultoa_base(va_arg(ap, unsigned long int), 10);
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
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
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_O(va_list ap, t_conv *obj)
{
	char			*tmp;

	tmp = ft_ultoa_base(va_arg(ap, unsigned long int), 8);
	if (obj->flags.hash && tmp[0] != '0')
		tmp = ft_strjoin("0", tmp);
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_p(va_list ap, t_conv *obj)
{
	void			*test;
	char			*tmp;

	test = va_arg(ap, void*);
	tmp = str_low(ft_itoa_base((int)test, 16));
	if (tmp[0] != '0' && ft_strlen(tmp) > 6)
		tmp = ft_strjoin("0x10", tmp);
	else if (tmp[0] != '0' && ft_strlen(tmp) == 6)
		tmp = ft_strjoin("0x100", tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
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
	if (obj->width)
		tmp = modify_width(obj, tmp);
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
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_c(va_list ap, t_conv *obj)
{
	char			tmp;
	char			*str;

	tmp = va_arg(ap, int);
	str = ft_strnew(1);
	str[0] = tmp;
	str[1] = '\0';
	if (obj->width)
		str = modify_width(obj, str);
	obj->size += ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (obj->size);
}

int	printf_s(va_list ap, t_conv *obj)
{
	char			*tmp;

	tmp = va_arg(ap, char *);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	// ft_strdel(&tmp);
	return (obj->size);
}

int	printf_per(t_conv *obj)
{
	char	*tmp;

	tmp = ft_strdup("%\0");
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	check_conv(va_list ap, t_conv *obj, char c)
{
	if (c == 'd' || c == 'i')
		return (printf_d(ap, obj));
	else if (c == 'D')
		return (printf_D(ap, obj));
	else if (c == 'u')
		return (printf_u(ap, obj));
	else if (c == 'U')
		return (printf_U(ap, obj));
	else if (c == 'o')
		return (printf_o(ap, obj));
	else if (c == 'O')
		return (printf_O(ap, obj));
	else if (c == 'x')
		return (printf_x(ap, obj));
	else if (c == 'X')
		return (printf_X(ap, obj));
	else if (c == 'c')
		return (printf_c(ap, obj));
	else if (c == 's')
		return (printf_s(ap, obj));
	else if (c == 'p')
		return (printf_p(ap, obj));
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

int		check_width(t_conv *obj, const char *num)
{
	int 	end;
	int 	tmp;

	end = 0;
	obj->width = atoi(num);
	tmp = obj->width;
	while (tmp /= 10)
		end++;
	end++;
	return (end);
}

int		check_prec(t_conv *obj, const char *num)
{
	int 	end;
	int 	tmp;

	end = 1;
	obj->b_prec = 1;
	if (ft_isdigit(num[1]))
	{
		obj->prec = atoi(&num[1]);
		tmp = obj->prec;
		while (tmp /= 10)
			end++;
		end++;
	}
	else
		obj->prec = 0;

	return (end);
}

void	set_struct(t_conv *obj)
{
	obj->b_prec = 0;
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
	if (str[*i] != '.' && ft_isdigit(str[*i]))
		(*i) += check_width(obj, &str[*i]);
	if (str[*i] == '.')
		(*i) += check_prec(obj, &str[*i]);
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
	char *tmp;

	tmp = (char*)malloc(sizeof(char) * 5);
	tmp = "Hello\0";
	test = (145 / 2.45);
	printf("Test %-10s with this %-10.5d with %-3c num1:%020lu num2:%X %% dec:% ld ptr:%p\n", "hel\tlo", 25, 'T', -9223372036854775807,  45630, -9223372036854775807, tmp);
	ft_printf("Test %-10s with this %-10.5d with %-3c num1:%020U num2:%X %% dec:% D ptr:%p\n", "hel\tlo", 25, 'T', -9223372036854775807, 45630, -9223372036854775807, tmp);
	return (0);
}
