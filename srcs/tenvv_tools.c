/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tenvv_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:11:41 by ptruffau          #+#    #+#             */
/*   Updated: 2018/07/04 14:11:42 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_envv	*get_tenvv(t_envv *envv, char *name)
{
	t_envv *tmp;

	tmp = envv;
	while (tmp)
	{
		if ((tmp->name) && ft_strequ(name, tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*get_tenvv_val(t_envv *envv, char *name)
{
	while (envv)
	{
		if (ft_strequ(name, envv->name))
			return (envv->value);
		envv = envv->next;
	}
	return (NULL);
}

int		envv_len(t_envv *envv)
{
	t_envv	*tmp;
	int		i;

	i = 0;
	tmp = envv;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_puttenvv(t_envv *envv)
{
	t_envv *tmp;

	tmp = envv;
	while (tmp != NULL && tmp->name != NULL)
	{
		ft_putstr("\033[1;32m\033[04m");
		ft_putstr(tmp->name);
		ft_putstr("\033[00m = ");
		ft_putendl(tmp->value);
		tmp = tmp->next;
	}
}

t_envv	*ft_changetenvv_val(t_envv *envv, char *name, char *new_val)
{
	t_envv *tmp;

	tmp = envv;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
		{
			ft_strdel(&tmp->value);
			if (!(tmp->value = ft_strdup(new_val)))
				return (NULL);
			return (envv);
		}
		tmp = tmp->next;
	}
	error("no such envv var", name);
	return (envv);
}
