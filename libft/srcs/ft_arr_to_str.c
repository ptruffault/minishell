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

char 	*ft_arr_to_str(char **arr)
{
	char *head;
	int i;
	int j;
	int size;

	i = 0;
	size = 0;
	head = ft_strnew(0);
	while (arr[i])
	{
		if (!(head = ft_realloc(head, size, size + ft_strlen(arr[i]))))
			return (NULL);
		j = 0;
		while (arr[i][j] != '\0')
			head[size++] = arr[i][j++];
		i++;
	}
	return (head);
}