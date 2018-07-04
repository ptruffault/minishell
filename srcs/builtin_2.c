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

void	ft_env(char **input, t_envv *envv)
{
	if (!inpu[1])
		ft_puttenvv(envv);
	else if (input[1][0] == '-')
	{
		if (input[1][1] == 'u')
		{
			if (!input[2])
				warning("need a var name as argument", NULL);
			else
				ft_unsetenvv(envv, input[2]);
		}
		if (

	}
}
