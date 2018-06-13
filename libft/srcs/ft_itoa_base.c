/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:57:04 by ptruffau          #+#    #+#             */
/*   Updated: 2017/11/16 11:11:47 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		f(intmax_t value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value <= -base || value >= base)
		f(value / base, base, str, i);
	if ((value % base) < 0)
		str[*i] = tmp[-(value % base)];
	else
		str[*i] = tmp[value % base];
	(*i)++;
}

char		*ft_itoa_base_intmax(intmax_t value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	if (base == 10 && value < 0)
		str[i++] = '-';
	if (value == 0)
		return ("0");
	if (value == 1)
		return ("1");
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}

static void		f_unintmax(uintmax_t value, unsigned int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value >= base)
		f(value / base, base, str, i);
	str[*i] = tmp[value % base];
	(*i)++;
}

char		*ft_itoa_base_unintmax(uintmax_t value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	if (value == 0)
		return ("0");
	if (value == 1)
		return ("1");
	f_unintmax(value, base, str, &i);
	str[i] = '\0';
	return (str);
}