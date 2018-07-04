/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:10:36 by ptruffau          #+#    #+#             */
/*   Updated: 2018/07/04 14:10:38 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(char **input)
{
	int i;

	i = 0;
	while (input[i])
	{
		ft_putstr(input[i++]);
		ft_putchar('\t');
	}
	ft_putchar('\n');
}
