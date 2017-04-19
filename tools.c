/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:36:13 by lhurt             #+#    #+#             */
/*   Updated: 2017/12/02 17:38:10 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*wchar_to_str(wchar_t num)
{
	char *str;

	if (num <= 0x7F)
	{
		str = (char*)malloc(sizeof(char) * 2);
		str[0] = num;
	}
	else if (num <= 0x7FF)
	{
		str = (char*)malloc(sizeof(char) * 3);
		str[0] = 192 | (((unsigned int)(num) >> 6) & 63);
		str[1] = 128 | ((unsigned int)(num) & 63);
	}
	else if (num <= 0xFFFF)
	{
		str = (char*)malloc(sizeof(char) * 4);
		str[0] = 224 | ((unsigned int)(num) >> 12) & 63);
		str[1] = 128 | ((unsigned int)(num) >> 6) & 63);
		str[2] = 128 | ((unsigned int)(num) & 63);
	}
	else if (num <= 0x10FFFF)
	{
		str = (char*)malloc(sizeof(char) * 5);
		str[0] = 240 | (((unsigned int)(num) >> 18) & 63);
		str[1] = 224 | ((unsigned int)(num) >> 12) & 63);
		str[2] = 128 | ((unsigned int)(num) >> 6) & 63);
		str[3] = 128 | ((unsigned int)(num) & 63);
	}
	if (str)
		str[ft_strlen(str) - 1] = '\0';
	return (str);
}
