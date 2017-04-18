/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:09:33 by lhurt             #+#    #+#             */
/*   Updated: 2017/03/06 20:09:34 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "printf.h"

char	*itoa_store(long *num, int base, int *i, int *count)
{
	char	*new;
	long	tmp;
	int		len;

	len = 0;
	if (*num < 0)
	{
		if (base == 10)
			(*i)++;
		(*num) *= -1;
	}
	tmp = *num;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = (len + (*i));
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char	*ft_itoa_base(int n, int base)
{
	char	*base_d = "0123456789ABCDEF";
	char	*new;
	long	num;
	int		i;
	int		count;

	i = 0;
	count = 0;
	num = n;
	new = itoa_store(&num, base, &i, &count);
	if (!new)
		return (NULL);
	if (i > 0)
		new[0] = '-';
	new[count] = '\0';
	while (num >= base)
	{
		new[--count] = base_d[num % base];
		num /= base;
	}
	new[i] = base_d[num % base];
	return (new);
}

char	*ltoa_store(long long int *num, int base, int *i, int *count)
{
	char			*new;
	long long int	tmp;
	int				len;

	len = 0;
	if (*num < 0)
	{
		if (base == 10)
			(*i)++;
		(*num) *= -1;
	}
	tmp = *num;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = (len + (*i));
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char	*ft_ltoa_base(long int n, int base)
{
	char		*base_d = "0123456789ABCDEF";
	char		*new;
	long long int	num;
	int			i;
	int			count;

	i = 0;
	count = 0;
	num = n;
	new = ltoa_store(&num, base, &i, &count);
	if (!new)
		return (NULL);
	if (i > 0)
		new[0] = '-';
	new[count] = '\0';
	while (num >= base)
	{
		new[--count] = base_d[num % base];
		num /= base;
	}
	new[i] = base_d[num % base];
	return (new);
}

char	*lltoa_store(long long *num, int base, int *i, int *count)
{
	char			*new;
	long long		tmp;
	int				len;

	len = 0;
	if (*num < 0)
	{
		if (base == 10)
			(*i)++;
		(*num) *= -1;
	}
	tmp = *num;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = (len + (*i));
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char	*ft_lltoa_base(long long n, int base)
{
	char		*base_d = "0123456789ABCDEF";
	char		*new;
	long long	num;
	int			i;
	int			count;

	i = 0;
	count = 0;
	num = n;
	new = ltoa_store(&num, base, &i, &count);
	if (!new)
		return (NULL);
	if (i > 0)
		new[0] = '-';
	new[count] = '\0';
	while (num >= base)
	{
		new[--count] = base_d[num % base];
		num /= base;
	}
	new[i] = base_d[num % base];
	return (new);
}

char	*utoa_store(unsigned int tmp, int base, unsigned int *count)
{
	char			*new;
	unsigned int	len;

	len = 0;
	while (tmp >= (unsigned)base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = len;
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char	*ft_utoa_base(unsigned int n, int base)
{
	char			*base_d = "0123456789ABCDEF";
	char			*new;
	unsigned int	count;

	count = 0;
	new = utoa_store(n, base, &count);
	if (!new)
		return (NULL);
	new[count] = '\0';
	while (n >= (unsigned int)base)
	{
		new[--count] = base_d[n % base];
		n /= base;
	}
	new[--count] = base_d[n % base];
	return (new);
}

char	*ultoa_store(unsigned long int tmp, int base, unsigned int *count)
{
	char				*new;
	unsigned long int	len;

	len = 0;
	while (tmp >= (unsigned)base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = len;
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char	*ft_ultoa_base(unsigned long int n, int base)
{
	char			*base_d = "0123456789ABCDEF";
	char			*new;
	unsigned int	count;

	count = 0;
	new = ultoa_store(n, base, &count);
	if (!new)
		return (NULL);
	new[count] = '\0';
	while (n >= (unsigned int)base)
	{
		new[--count] = base_d[n % base];
		n /= base;
	}
	new[--count] = base_d[n % base];
	return (new);
}

char	*ulltoa_store(unsigned long long tmp, int base, unsigned int *count)
{
	char				*new;
	unsigned long long	len;

	len = 0;
	while (tmp >= (unsigned)base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = len;
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char	*ft_ulltoa_base(unsigned long long n, int base)
{
	char			*base_d = "0123456789ABCDEF";
	char			*new;
	unsigned int	count;

	count = 0;
	new = ultoa_store(n, base, &count);
	if (!new)
		return (NULL);
	new[count] = '\0';
	while (n >= (unsigned int)base)
	{
		new[--count] = base_d[n % base];
		n /= base;
	}
	new[--count] = base_d[n % base];
	return (new);
}

char	*basetoa_store(int *num, int base, int *i, int *count)
{
	char	*new;
	int		tmp;
	int		len;

	len = 0;
	if (*num < 0)
	{
		if (base == 10)
			(*i)++;
		(*num) *= -1;
	}
	tmp = *num;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = (len + (*i));
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char	*ft_sctoa_base(signed char n, int base)
{
	char	*base_d = "0123456789ABCDEF";
	char	*new;
	int		num;
	int		i;
	int		count;

	i = 0;
	count = 0;
	num = n;
	new = basetoa_store(&num, base, &i, &count);
	if (!new)
		return (NULL);
	if (i > 0)
		new[0] = '-';
	new[count] = '\0';
	while (num >= base)
	{
		new[--count] = base_d[num % base];
		num /= base;
	}
	new[i] = base_d[num % base];
	return (new);
}

char	*usctoa_store(unsigned char tmp, int base, unsigned int *count)
{
	char			*new;
	unsigned int	len;

	len = 0;
	while (tmp >= (unsigned int)base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = len;
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char	*ft_usctoa_base(unsigned char n, int base)
{
	char			*base_d = "0123456789ABCDEF";
	char			*new;
	unsigned int	count;

	count = 0;
	new = usctoa_store(n, base, &count);
	if (!new)
		return (NULL);
	new[count] = '\0';
	while (n >= (unsigned int)base)
	{
		new[--count] = base_d[n % base];
		n /= base;
	}
	new[--count] = base_d[n % base];
	return (new);
}


char	*ft_sitoa_base(short int n, int base)
{
	char	*base_d = "0123456789ABCDEF";
	char	*new;
	int		num;
	int		i;
	int		count;

	i = 0;
	count = 0;
	num = n;
	new = basetoa_store(&num, base, &i, &count);
	if (!new)
		return (NULL);
	if (i > 0)
		new[0] = '-';
	new[count] = '\0';
	while (num >= base)
	{
		new[--count] = base_d[num % base];
		num /= base;
	}
	new[i] = base_d[num % base];
	return (new);
}

char	*usitoa_store(unsigned short int tmp, int base, unsigned int *count)
{
	char			*new;
	unsigned int	len;

	len = 0;
	while (tmp >= (unsigned)base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = len;
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char	*ft_usitoa_base(unsigned short int n, int base)
{
	char			*base_d = "0123456789ABCDEF";
	char			*new;
	unsigned int	count;

	count = 0;
	new = usitoa_store(n, base, &count);
	if (!new)
		return (NULL);
	new[count] = '\0';
	while (n >= (unsigned int)base)
	{
		new[--count] = base_d[n % base];
		n /= base;
	}
	new[--count] = base_d[n % base];
	return (new);
}
