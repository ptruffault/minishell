/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:28:58 by ptruffau          #+#    #+#             */
/*   Updated: 2017/12/03 16:15:49 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nw(char *s, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			n++;
		i++;
	}
	if (s[i - 1] != c && !s[i])
		n++;
	return (n);
}

static int	ft_lenword(char const *s, char c, int i, int cstm)
{
	cstm = 0;
	while (s[i] != c && s[i])
	{
		cstm++;
		i++;
	}
	return (cstm);
}

static void	ft_j_loop(char const *s, char c, char **new, int newindex)
{
	int j;

	j = -1;
	while (s[++j] && s[j] != c)
		new[newindex][j] = s[j];
	new[newindex][j] = '\0';
}

char		**ft_strsplit(char const *s, char c)
{
	int		cstm;
	int		i;
	char	**new;
	int		newindex;

	if (!s || !(new = (char **)malloc(sizeof(char*) * ft_nw((char *)s, c) + 1)))
		return (NULL);
	newindex = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		cstm = ft_lenword(s, c, i, cstm);
		new[newindex] = ft_strnew(cstm);
		if (!new[newindex])
			return (NULL);
		ft_j_loop(s + i, c, new, newindex++);
		i += cstm;
	}
	new[newindex] = NULL;
	return (new);
}
