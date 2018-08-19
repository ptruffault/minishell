/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:10:22 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/21 14:10:26 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_is_quote(char *str)
{
	char *ptr;

	if (*str == '"' || *str == '\'')
	{
		if ((ptr = ft_strchr(str + 1, *str)))
			return (1);
		return (-1);
	}
	return (0);
}

static int		word_len(char *str)
{
	int ret;
	int i;

	ret = ft_is_quote(str);
	i = 0;
	if (ret == -1)
	{
		error(" invalid quote : missing end symbol", str);
		return (-1);
	}
	if (ret == 0)
	{
		while (!(IS_SPACE(str[i])) && str[i] != '\0')
			i++;
		return (i);
	}
	if (ret == 1)
		return (ft_strchr(str + 1, *str) - (str + 1));
	return (-1);
}

static char		**init_tab(char *s)
{
	int		i;
	int		n;
	char	*ptr;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (!(IS_SPACE(s[i])))
		{
			if ((s[i] == '"' || s[i] == '\'')
			&& (ptr = ft_strchr(&s[i + 1], s[i])))
				i = i + (ptr - &s[i]);
			else
			{
				while (!(IS_SPACE(s[i])) && s[i] != '\0')
					i++;
			}
			n++;
		}
		if (s[i] != '\0')
			i++;
	}
	return ((char **)malloc(sizeof(char *) * (n + 1)));
}

static char		*get_next_word(char *str)
{
	char	*word;
	int		len;

	if ((len = word_len(str)) == -1)
		return (NULL);
	if (!(word = ft_strnew(len)))
		return (NULL);
	if (ft_is_quote(str))
		word = ft_strncpy(word, str + 1, len);
	else
		word = ft_strncpy(word, str, len);
	return (word);
}

char			**ft_strsplit_word(char *str)
{
	char	**tab;
	int		k;
	int		i;

	if (!(tab = init_tab(str)))
		return (NULL);
	k = 0;
	i = 0;
	while (str[i])
	{
		if (!(IS_SPACE(str[i])))
		{
			if (!(tab[k++] = get_next_word(&str[i])))
			{
				ft_freestrarr(tab);
				return (NULL);
			}
			i = i + word_len(&str[i]) + 2 * ft_is_quote(&str[i]);
		}
		else
			i++;
	}
	tab[k] = NULL;
	return (tab);
}
