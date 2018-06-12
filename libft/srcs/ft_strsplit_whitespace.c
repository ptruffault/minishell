/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:42:44 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 15:52:02 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nw(char *s)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (IS_SPACE(s[i]))
		i++;
	while (s[i])
	{
		if (IS_SPACE(s[i]) && !(IS_SPACE(s[i - 1])))
			n++;
		i++;
	}
	if (!(IS_SPACE(s[i - 1])) && !s[i])
		n++;
	return (n);
}

char		*get_next_word(char *str)
{
	char	*word;
	int		j;

	j = 0;
	word = NULL;
	while (!(IS_SPACE(str[j])) && str[j] != '\0')
		j++;
	if (str[j] != '\0')
	{
		if (!(word = ft_strnew(j)))
		{
			error("allocation failed", "ft_strsplit_whitespace");
			return (NULL);
		}
		word = ft_strncpy(word, str, j);
	}
	return (word);
}

char		**ft_strsplit_whitespace(char *str)
{
	int		i;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	tab = NULL;
	if (!(tab = (char **)malloc(sizeof(char *) * ft_nw(str) + 1)))
	{
		error("allocation failed", "ft_strsplit_whitespace");
		return (NULL);
	}
	while (str[i] != '\0')
	{
		while (IS_SPACE(str[i]))
			i++;
		if (str[i] != '\0')
		{
			tab[k] = get_next_word(&str[i]);
			i = i + ft_strlen(tab[k++]);
		}
	}
	tab[k] = NULL;
	return (tab);
}
