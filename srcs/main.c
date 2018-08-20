/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:11:06 by ptruffau          #+#    #+#             */
/*   Updated: 2018/07/04 14:11:07 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_tenvv(t_envv *envv, char **tab_envv)
{
	int		i;
	int		len;
	t_envv	*tmp;

	i = 0;
	tmp = envv;
	len = ft_strarrlen(tab_envv);
	while (i < len)
	{
		if (!(tmp->name = get_name(tab_envv[i]))
		|| !(tmp->value = get_value(tab_envv[i])))
			return ;
		i++;
		if (!(tmp->next = new_tenvv()))
			return ;
		tmp = tmp->next;
	}
	tmp = NULL;
}

void	ft_disp(t_envv *envv, int argc, char **argv)
{
	if (argc != 1)
	{
		ft_putstr(argv[1]);
		ft_putchar('>');
	}
	else
	{
		ft_putstr("\033[1;32mminishell\033[00m:[\033[01;34m\033[04m");
		ft_putstr(get_tenvv_val(envv, "PWD"));
		ft_putendl("\033[00m]");
	}
}

int		main(int argc, char **argv, char **envv)
{
	t_envv	*my_envv;

	if (!(my_envv = new_tenvv()))
	{
		error("init envvironnement failure", "t_envv");
		return (-1);
	}
	init_tenvv(my_envv, envv);
	while (1)
	{
		ft_disp(my_envv, argc, argv);
		my_envv = read_cmd(my_envv, ft_get_input());
	}
	return (0);
}
