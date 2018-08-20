/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:15:39 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/21 14:15:41 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_color(char *s)
{
	char *tmp;
	char *ret;

	tmp = ft_strjoin(s, NORMAL);
	ret = ft_strjoin(BLEU , tmp);
	ft_strdel(&tmp);
	return (ret);
}

char	*ft_strpull(char *src, char *ptr, int len, char *value)
{
	char *new;
	char *part1;
	char *part2;
	char *tmp;

	if ((!(value = ft_color(value)))
	||	!(part1 = ft_strndup(src, ptr - src))
	|| !(part2 = ft_strdup(ptr + len + 1))
	|| !(tmp = ft_strjoin(part1, value))
	|| !(new = ft_strjoin_fr(tmp, part2)))
		return (NULL);
	ft_strdel(&src);
	ft_strdel(&part1);
	return (new);
}
