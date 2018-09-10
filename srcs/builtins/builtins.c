/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:10:52 by ptruffau          #+#    #+#             */
/*   Updated: 2018/07/04 14:10:54 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	change_dir(char *path, t_envv *envv)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		ft_setenv(envv, "OLDPWD", cwd);
		ft_setenv(envv, "PWD", getcwd(buff, 4096));
	}
	else
	{
		if (access(path, F_OK) == -1)
			error("no such file or directory: ", path);
		else if (access(path, R_OK) == -1)
			error("permission denied: ", path);
		else
			error("not a directory: ", path);
	}
}

void		ft_cd(char **input, t_envv *envv)
{
	if (!(input[1]))
		change_dir(get_tenvv_val(envv, "HOME"), envv);
	else if (input[1][0] == '-' && input[1][1] == '\0')
		change_dir(get_tenvv_val(envv, "OLDPWD"), envv);
	else if (input[1])
		change_dir(input[1], envv);
}

t_envv		*ft_unsetenv(t_envv *envv, char *name)
{
	t_envv *tmp;
	t_envv *prev;

	tmp = envv->next;
	prev = envv;
	if (ft_strequ(envv->name, name))
	{
		tmp = envv->next;
		del_tenvv(envv);
		return (tmp);
	}
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
		{
			prev->next = tmp->next;
			del_tenvv(tmp);
			return (envv);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	warning("there is no such var name in env", name);
	return (envv);
}

t_envv		*ft_setenv(t_envv *envv, char *name, char *value)
{
	t_envv *new;
	t_envv *tmp;

	if ((tmp = get_tenvv(envv, name)))
	{
		if (!(envv = ft_changetenvv_val(envv, name, value)))
			return (NULL);
		return (envv);
	}
	if (!(new = new_tenvv())
	|| !(new->name = ft_strdup(name))
	|| !(new->value = ft_strdup(value)))
		return (NULL);
	new->next = envv;
	return (new);
}

void		ft_echo(char **input)
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
