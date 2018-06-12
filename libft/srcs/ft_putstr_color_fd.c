/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:33:25 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 16:34:15 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_color_fd(char *str, char *color, int fd)
{
	char *color_str;

	color_str = ft_strjoin(color, str);
	ft_putstr_fd(color_str, fd);
	free(color_str);
	ft_putstr_fd(NORMAL, fd);
}

void	ft_putstr_color(char *str, char *color)
{
	ft_putstr_color_fd(str, color, 1);
}
