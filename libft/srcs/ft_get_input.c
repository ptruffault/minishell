/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:49:50 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/21 14:50:01 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_input(void)
{
	char	*input;
	int		ret;
	char	buf;
	int		i;
	int		count;

	if (!(input = ft_strnew(1)))
		return (NULL);
	count = 1;
	i = 0;
	while ((ret = read(0, &buf, 1)) && buf != '\n')
	{
		input[i++] = buf;
		input = ft_realloc(input, count, count + 1);
		count++;
	}
	input[i] = '\0';
	if (!ret)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
