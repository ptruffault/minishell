/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:40:10 by ptruffau          #+#    #+#             */
/*   Updated: 2018/08/20 14:40:11 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		envv_len(t_envv *envv)
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

static char	**put_in_tab(t_envv *envv)
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

static int	ft_exec(char *path, char **args, t_envv *envv)
{
	pid_t	pid;
	char	**arr;

	if ((pid = fork()) == 0)
	{
		if (!(arr = put_in_tab(envv)))
		{
			error("t_envv convertion **arr failed", NULL);
			ft_strdel(&path);
			return (-1);
		}
		execve(path, args, arr);
	}
	else if (pid < 0)
	{
		error("Fork failed to create a new process", path);
		ft_strdel(&path);
		return (-1);
	}
	wait(&pid);
	return (1);
}

void 	run_bin(char **args, t_envv *envv)
{
	char *bin_path;

	if ((bin_path = check_bin(args, envv))
	&& (ft_exec(bin_path, args, envv) > 0))
		ft_strdel(&bin_path);
	else if (!bin_path)
		error("command not found", NULL);
}

t_envv		*read_cmd(t_envv *envv, char *input, char **arr)
{
	char	**cmd;
	int		inf;

	if (check_void_input(input))
		return (envv);
	else if (!(cmd = ft_correct(ft_strsplit_word(input), envv)))
		return (envv);
	inf = check_builtin(cmd);
	if (inf == 1)
		envv = run_builtin(cmd, envv, arr);
	else if (inf == 0)
		run_bin(cmd, envv);
	ft_freestrarr(cmd);
	return (envv);
}
