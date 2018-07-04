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

void	ft_pwd(t_envv *e)
{
	ft_putstr("\033[1;32m\033[04m\nPrint Working Directory:\033[00m\n");
	ft_putendl(get_tenvv_val(e, "PWD"));
	ft_putchar('\n');
}
