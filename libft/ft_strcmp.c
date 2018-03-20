/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:17:09 by ptruffau          #+#    #+#             */
/*   Updated: 2017/11/16 13:17:30 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strcmp_castless(char *s1, char *s2)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (ft_isalnum(s1[i]) == 0)
		i++;
	while (ft_isalnum(s2[j]) == 0)
		j++;
	while (s1[i] != '\0' && s2[j] != '\0' && (s1[i] == s2[j] || 
	(ft_isalpha(s1[i] - 32) && s1[i] - 32 == s2[j])			 ||
	(ft_isalpha(s1[i] + 32) && s1[i] + 32 == s2[j])))
	{
		i++;
		j++;
	}
	if (ft_ismin(s1[i]) == 1 && ft_ismaj(s2[j]) == 1)
		return ((unsigned char)s1[i] - ((unsigned char)s2[j] + 32));
	if (ft_ismaj((unsigned char)s1[i]) == 1 && ft_ismin((unsigned char)s2[j]) == 1)
		return ((s1[i] + 32) - s2[j]);
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}