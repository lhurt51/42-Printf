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
	char			*rtn;
	char			conv;
	int				b_con:1;
	int				b_prec:1;
	t_flags			flags;
	t_len			len;
	unsigned int	width;
	unsigned int	prec;
	unsigned int	size;
}					t_conv;

void	*error(char *msg);
char	*str_low(char *str);
int		wchar_len(wchar_t num);
int		wstr_len(wchar_t *str);
char	*wchar_to_str(wchar_t num);
char	*wstr_to_str(wchar_t *str);
char	*ft_itoa_base(int n, int base);
char	*ft_utoa_base(unsigned int n, int base);
char	*ft_ltoa_base(long n, int base);
char	*ft_ultoa_base(unsigned long int n, int base);
char	*ft_lltoa_base(long long n, int base);
char	*ft_ulltoa_base(unsigned long long n, int base);
char	*ft_sctoa_base(signed char n, int base);
char	*ft_usctoa_base(unsigned char n, int base);
char	*ft_sitoa_base(short int n, int base);
char	*ft_usitoa_base(unsigned short int n, int base);
char	*ft_jtoa_base(intmax_t n, int base);
char	*ft_ujtoa_base(uintmax_t n, int base);
char	*ft_ztoa_base(size_t n, int base);
int		ft_printf(const char *str, ...);
// @$(CC) $(FLAG) $(OBJS) $(LFLAG) -o $(NAME)
// http://www.cplusplus.com/reference/cstdio/printf/
// https://linux.die.net/man/3/printf
// http://man7.org/linux/man-pages/man3/stdarg.3.html
// http://personal.ee.surrey.ac.uk/Personal/R.Bowden/C/printf.html
// https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

#endif
