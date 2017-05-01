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

#include "printf.h"

char *switch_width(t_conv *obj, char *str, char *space, unsigned int len)
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

	return (str);
}

char *modify_width(t_conv *obj, char *str)
{
	unsigned int 	len;
	char			*space;

	len = ft_strlen(str) - obj->flags.plus;
	if (!len)
		len = 1;
	if (obj->flags.zero && !obj->b_prec)
		space = ft_strdup("0");
	else
		space = ft_strdup(" ");
	if (len < obj->width)
		str = switch_width(obj, str, space, len);
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

char *call_len_d(va_list ap, t_conv *obj)
{
	if (obj->len.hh)
		return (ft_sctoa_base(va_arg(ap, int), 10));
	else if (obj->len.h)
		return (ft_sitoa_base(va_arg(ap, int), 10));
	else if (obj->len.l)
		return (ft_ltoa_base(va_arg(ap, long), 10));
	else if (obj->len.ll)
		return (ft_lltoa_base(va_arg(ap, long long), 10));
	else if (obj->len.j)
		return (ft_jtoa_base(va_arg(ap, intmax_t), 10));
	else if (obj->len.z)
		return (ft_ztoa_base(va_arg(ap, size_t), 10));
	else
		return (ft_itoa_base(va_arg(ap, int), 10));
}

int	printf_d(va_list ap, t_conv *obj)
{
	char	*tmp;

	tmp = call_len_d(ap, obj);
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->flags.zero && obj->width)
		tmp = modify_width(obj, tmp);
	if (obj->flags.plus && tmp[0] != '-')
		tmp = ft_strjoin("+", tmp);
	if (obj->flags.space && tmp[0] != '-')
		tmp = ft_strjoin(" ", tmp);
	if (!obj->flags.zero && obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	obj->rtn = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_D(va_list ap, t_conv *obj)
{
	obj->len.l = 1;
	return (printf_d(ap, obj));
}

char *call_len_u(va_list ap, t_conv *obj)
{
	if (obj->len.hh)
		return (ft_usctoa_base(va_arg(ap, unsigned int), 10));
	else if (obj->len.h)
		return (ft_usitoa_base(va_arg(ap, unsigned int), 10));
	else if (obj->len.l)
		return (ft_ultoa_base(va_arg(ap, unsigned long int), 10));
	else if (obj->len.ll)
		return (ft_ulltoa_base(va_arg(ap, unsigned long long int), 10));
	else if (obj->len.j)
		return (ft_ujtoa_base(va_arg(ap, uintmax_t), 10));
	else if (obj->len.z)
		return (ft_ztoa_base(va_arg(ap, size_t), 10));
	else
		return (ft_utoa_base(va_arg(ap, unsigned int), 10));
}

int	printf_u(va_list ap, t_conv *obj)
{
	char	*tmp;

	tmp = call_len_u(ap, obj);
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	obj->rtn = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_U(va_list ap, t_conv *obj)
{
	obj->len.l = 1;
	return (printf_u(ap, obj));
}

char *call_len_o(va_list ap, t_conv *obj)
{
	if (obj->len.hh)
		return (ft_usctoa_base(va_arg(ap, unsigned int), 8));
	else if (obj->len.h)
		return (ft_usitoa_base(va_arg(ap, unsigned int), 8));
	else if (obj->len.l)
		return (ft_ultoa_base(va_arg(ap, unsigned long int), 8));
	else if (obj->len.ll)
		return (ft_ulltoa_base(va_arg(ap, unsigned long long int), 8));
	else if (obj->len.j)
		return (ft_ujtoa_base(va_arg(ap, uintmax_t), 8));
	else if (obj->len.z)
		return (ft_ztoa_base(va_arg(ap, size_t), 8));
	else
		return (ft_utoa_base(va_arg(ap, unsigned int), 8));
}

int	printf_o(va_list ap, t_conv *obj)
{
	char			*tmp;

	tmp = call_len_o(ap, obj);
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->flags.hash && tmp[0] != '0')
		tmp = ft_strjoin("0", tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	obj->rtn = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_O(va_list ap, t_conv *obj)
{
	obj->len.l = 1;
	return (printf_o(ap, obj));
}

int	printf_p(va_list ap, t_conv *obj)
{
	uintmax_t		test;
	char			*tmp;

	test = va_arg(ap, uintmax_t);
	tmp = str_low(ft_ujtoa_base(test, 16));
	tmp = ft_strjoin("0x", tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	obj->rtn = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

char *call_len_x(va_list ap, t_conv *obj)
{
	if (obj->len.hh)
		return (ft_usctoa_base(va_arg(ap, unsigned int), 16));
	else if (obj->len.h)
		return (ft_usitoa_base(va_arg(ap, unsigned int), 16));
	else if (obj->len.l)
		return (ft_ultoa_base(va_arg(ap, unsigned long int), 16));
	else if (obj->len.ll)
		return (ft_ulltoa_base(va_arg(ap, unsigned long long int), 16));
	else if (obj->len.j)
		return (ft_ujtoa_base(va_arg(ap, uintmax_t), 16));
	else if (obj->len.z)
		return (ft_ztoa_base(va_arg(ap, size_t), 16));
	else
		return (ft_utoa_base(va_arg(ap, unsigned int), 16));
}

int	printf_x(va_list ap, t_conv *obj)
{
	char			*tmp;

	tmp = str_low(call_len_x(ap, obj));
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->flags.hash && tmp[0] != '0')
		tmp = ft_strjoin("0x", tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	obj->rtn = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

char *call_len_X(va_list ap, t_conv *obj)
{
	if (obj->len.hh)
		return (ft_usctoa_base(va_arg(ap, unsigned int), 16));
	else if (obj->len.h)
		return (ft_usitoa_base(va_arg(ap, unsigned int), 16));
	else if (obj->len.l)
		return (ft_ultoa_base(va_arg(ap, unsigned long int), 16));
	else if (obj->len.ll)
		return (ft_ulltoa_base(va_arg(ap, unsigned long long int), 16));
	else if (obj->len.j)
		return (ft_ujtoa_base(va_arg(ap, uintmax_t), 16));
	else if (obj->len.z)
		return (ft_ztoa_base(va_arg(ap, size_t), 16));
	else
		return (ft_utoa_base(va_arg(ap, unsigned int), 16));
}

int	printf_X(va_list ap, t_conv *obj)
{
	char			*tmp;

	tmp = call_len_X(ap, obj);
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->flags.hash && tmp[0] != '0')
		tmp = ft_strjoin("0X", tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	obj->rtn = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_c(va_list ap, t_conv *obj)
{
	char			tmp;
	char			*str;

	tmp = va_arg(ap, int);
	if (!tmp)
	{
		obj->b_con = 1;
		str = ft_strdup("");
		ft_putchar('\0');
	}
	else
	{
		str = ft_strnew(1);
		str[0] = tmp;
	}
	if (obj->width)
		str = modify_width(obj, str);
	obj->size += ft_strlen(str);
	obj->rtn = ft_strdup(str);
	ft_strdel(&str);
	return (obj->size);
}

char	*call_len_s(va_list ap, t_conv *obj)
{
	if (obj->len.l)
		return (wstr_to_str(va_arg(ap, wchar_t *)));
	else
		return (va_arg(ap, char *));
}

int	printf_s(va_list ap, t_conv *obj)
{
	char		*holder;
	char		*tmp;

	holder = call_len_s(ap, obj);
	if (!holder)
	{
		obj->b_con = 1;
		if (!obj->prec || obj->prec >= 6)
			tmp = ft_strdup("(null)");
		else
			tmp = ft_strdup("");
	}
	else
		tmp = ft_strdup(holder);
	if (obj->prec)
		tmp = ft_strsub(tmp, 0, obj->prec);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	obj->rtn = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	printf_ws(va_list ap, t_conv *obj)
{
	obj->len.l = 1;
	return (printf_s(ap, obj));
}

int	printf_per(t_conv *obj)
{
	char	*tmp;

	tmp = ft_strdup("%\0");
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	obj->rtn = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}

int	check_conv(va_list ap, t_conv *obj, char c)
{
	obj->conv = c;
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
	else if (c == 'C')
		return (printf_c(ap, obj));
	else if (c == 's')
		return (printf_s(ap, obj));
	else if (c == 'S')
		return (printf_ws(ap, obj));
	else if (c == 'p')
		return (printf_p(ap, obj));
	else if (c == '%')
		return (printf_per(obj));
	else
		return ((int)error(" No specified conversion"));
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
	if (num[0] == '0' && num[1] > '0')
	{
		obj->width = atoi(&num[1]);
		end++;
	}
	else
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

int		check_len(t_conv *obj, const char *str)
{
	if (ft_strnequ(str, "hh\0", 2))
	{
		obj->len.hh = 1;
		return (2);
	}
	else if (str[0] == 'h')
		obj->len.h = 1;
	else if (ft_strnequ(str, "ll\0", 2))
	{
		obj->len.ll = 1;
		return (2);
	}
	else if (str[0] == 'l')
		obj->len.l = 1;
	else if (str[0] == 'j')
		obj->len.j = 1;
	else if (str[0] == 'z')
		obj->len.z = 1;
	else
		return (0);
	return (1);
}

void	set_struct(t_conv *obj)
{
	obj->b_con = 0;
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
	if (obj->flags.space)
		while (str[*i] == ' ')
			(*i)++;
	if (obj->flags.zero && check_flag(obj, str[*i]))
		(*i)++;
	if (str[*i] != '.' && ft_isdigit(str[*i]))
		(*i) += check_width(obj, &str[*i]);
	if (str[*i] == '.')
		(*i) += check_prec(obj, &str[*i]);
	if (ft_isalpha(str[*i]))
		(*i) += check_len(obj, &str[*i]);
	if (!check_conv(ap, obj, str[*i]))
		return (0);
	(*i)++;
	return (obj->size);
}

int		any_len(t_conv *obj)
{
	if (obj->len.hh || obj->len.h || obj->len.ll || obj->len.j
		|| obj->len.z)
		return (1);
	return (0);
}

char	*print_flag(t_conv *obj)
{
	if (obj->flags.plus)
		return ("+\0");
	else if (obj->flags.space)
		return ("space\0");
	else if (obj->flags.hash)
		return ("#\0");
	else if (obj->flags.zero)
		return ("0\0");
	else
		return (NULL);
}

char	*print_len(t_conv *obj)
{
	if (obj->len.hh)
		return ("hh\0");
	else if (obj->len.h)
		return ("h\0");
	else if (obj->len.l)
		return ("l\0");
	else if (obj->len.ll)
		return ("ll\0");
	else if (obj->len.j)
		return ("j\0");
	else if (obj->len.z)
		return ("z\0");
	else
		return (NULL);
}

int		flag_d(t_conv *obj)
{
	if (obj->flags.hash)
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			ft_strjoin(" does work with flag:", print_flag(obj)))));
	if (obj->conv == 'D' && any_len(obj))
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			" does work with any len")));
	return (1);
}

int		flag_u(t_conv *obj)
{
	if (obj->flags.hash || obj->flags.plus || obj->flags.space)
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			ft_strjoin(" does work with flag:", print_flag(obj)))));
	if (obj->conv == 'U' && any_len(obj))
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			" does work with any len")));
	return (1);
}

int		flag_o(t_conv *obj)
{
	if (obj->flags.plus || obj->flags.space)
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			ft_strjoin(" does work with flag:", print_flag(obj)))));
	if (obj->conv == 'O' && any_len(obj))
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			" does work with any len")));
	return (1);
}

int		flag_x(t_conv *obj)
{
	if (obj->flags.plus || obj->flags.space)
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			ft_strjoin(" does work with flag:", print_flag(obj)))));
	return (1);
}

int		flag_c(t_conv *obj)
{
	if (obj->flags.plus || obj->flags.space || obj->flags.hash
		|| obj->flags.zero)
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			ft_strjoin(" does work with flag:", print_flag(obj)))));
	if (any_len(obj))
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			ft_strjoin(" does work with len:", print_len(obj)))));
	if (obj->conv == 'C' && any_len(obj))
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			" does work with any len")));
	return (1);
}

int		flag_s(t_conv *obj)
{
	if (obj->flags.plus || obj->flags.space || obj->flags.hash
		|| obj->flags.zero)
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			ft_strjoin(" does work with flag:", print_flag(obj)))));
	if (any_len(obj))
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			ft_strjoin(" does work with len:", print_len(obj)))));
	if (obj->conv == 'S' && any_len(obj))
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			" does work with any len")));
	return (1);
}

int		flag_p(t_conv *obj)
{
	if (obj->flags.plus || obj->flags.space || obj->flags.hash
		|| obj->flags.zero)
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			ft_strjoin(" does work with flag:", print_flag(obj)))));
	if (any_len(obj) || obj->len.l)
		return ((int)error(ft_strjoin(ft_strjoin(" conv:", &obj->conv),
			" does work with any len")));
	return (1);
}

int		can_mix(t_conv *obj)
{
	if (obj->conv == 'd' || obj->conv == 'i' || obj->conv == 'D')
		return (flag_d(obj));
	else if (obj->conv == 'u' || obj->conv == 'U')
		return (flag_u(obj));
	else if (obj->conv == 'o' || obj->conv == 'O')
		return (flag_o(obj));
	else if (obj->conv == 'x' || obj->conv == 'X')
		return (flag_x(obj));
	else if (obj->conv == 'c' || obj->conv == 'C')
		return (flag_c(obj));
	else if (obj->conv == 's' || obj->conv == 'S')
		return (flag_s(obj));
	else if (obj->conv == 'p')
		return (flag_p(obj));
	else if (obj->conv == '%')
		return (1);
	else
		return (0);
}

char	*set_up_conv(va_list ap, const char *str, int *i, int *b_con)
{
	t_conv	*obj;
	char	*tmp;

	obj = malloc(sizeof(t_conv));
	if (!obj)
		return (0);
	set_struct(obj);
	if (!check_all(ap, obj, str, i) || !can_mix(obj))
	{
		if ((*b_con = obj->b_con))
			(*i)++;
		return (0);
	}
	tmp = ft_strdup(obj->rtn);
	ft_strdel(&obj->rtn);
	free(obj);
	return (tmp);
}

char	*first_or(char *rtn, char *tmp, int i)
{
	if (i == 0)
		rtn = ft_strdup(tmp);
	else
		rtn = ft_strjoin(rtn, tmp);
	return (rtn);
}

int		search_params(va_list ap, const char *str, char **rtn, int count)
{
	char	*tmp;
	int		i;
	int		con;

	i = 0;
	tmp = NULL;
	while (str[i])
	{
		count = i;
		if (str[i] == '%' && !(tmp = set_up_conv(ap, str, &i, &con)) && !con)
				return (0);
		if (tmp)
		{
			*rtn = first_or(*rtn, tmp, count++);
			tmp = NULL;
		}
		if (str[i] != '%')
		{
			*rtn = first_or(*rtn, ft_strsub(&str[i], 0, 1), count);
			if (str[i])
				i++;
		}
	}

	return (1);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*rtn;
	int		len;

	rtn = NULL;
	va_start(ap, str);
	if (!search_params(ap, str, &rtn, 0))
		return (0);
	ft_putstr(rtn);
	len = ft_strlen(rtn);
	ft_strdel(&rtn);
	va_end(ap);
	return (len);
}
