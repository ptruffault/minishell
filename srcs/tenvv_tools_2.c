/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tenvv_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:11:52 by ptruffau          #+#    #+#             */
/*   Updated: 2018/07/04 14:11:54 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_envv	*new_tenvv(void)
{
	t_envv *new;

	if (!(new = (t_envv *)malloc(sizeof(t_envv))))
		return (NULL);
	new->next = NULL;
	new->name = NULL;
	new->value = NULL;
	return (new);
}

t_envv	*ft_tenvv_cpy(t_envv *src)
{
	t_envv *dest;

	while(src)
	{
		dest = new_tenvv();
		dest->name = ft_strdup(src->name);
		dest->value = ft_strdup(src->value);
		src = src->next;
		dest = dest->next;
	}
	return (dest);
}



void	del_tenvv(t_envv *envv)
{
	ft_strdel(&envv->name);
	ft_strdel(&envv->value);
	envv->next = NULL;
	free(envv);
}

void	ft_free_tenvv(t_envv *envv)
{
	t_envv *tmp;

	while (envv)
	{
		tmp = envv;
		envv = envv->next;
		del_tenvv(tmp);
	}
}

char	**put_in_tab(t_envv *envv)
{
	char	**tab;
	t_envv	*tmp;
	int		i;
	int		len;

	i = 0;
	tmp = envv;
	len = envv_len(envv) - 1;
	if (!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (!(tab[i++] = get_equal(tmp->name, tmp->value)))
			return (NULL);
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}
