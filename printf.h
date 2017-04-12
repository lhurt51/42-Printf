/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:06:58 by lhurt             #+#    #+#             */
/*   Updated: 2017/03/02 18:07:02 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_flags
{
	int				plus:1;
	int				minus:1;
	int				space:1;
	int				hash:1;
	int				zero:1;
}					t_flags;

typedef struct		s_len
{
	int				hh:1;
	int				h:1;
	int				l:1;
	int				ll:1;
	int				j:1;
	int				z:1;
}					t_len;

typedef struct		s_conv
{
	int				b_prec:1;
	t_flags			flags;
	t_len			len;
	unsigned int	width;
	unsigned int	prec;
	unsigned int	size;
}					t_conv;

char	*ft_itoa_base(int n, int base);
char	*ft_utoa_base(unsigned int n, int base);
char	*ft_ltoa_base(long n, int base);
char	*ft_ultoa_base(unsigned long int n, int base);
// http://www.cplusplus.com/reference/cstdio/printf/
// https://linux.die.net/man/3/printf
// http://man7.org/linux/man-pages/man3/stdarg.3.html
// http://personal.ee.surrey.ac.uk/Personal/R.Bowden/C/printf.html
// https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

#endif
