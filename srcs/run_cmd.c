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

static int	run_bin(char *path, char **args, t_envv *envv)
{
	pid_t	pid;
	char	**arr;

	if ((pid = fork()) == 0)
	{
		if (!(arr = put_in_tab(envv)))
		{
			error("t_envv convertion **arr failed", NULL);
			free(path);
			return (-1);
		}
		execve(path, args, arr);
	}
	else if (pid < 0)
	{
		error("Fork failed to create a new process", path);
		free(path);
		return (-1);
	}
	wait(&pid);
	return (1);
}

t_envv		*check_and_run_cmd(t_envv *envv, char **input)
{
	int		inf;
	t_envv	*tmp;
	char	*bin_path;

	inf = check_builtin(input);
	if (inf == 1)
	{
		if (!(tmp = run_builtin(input, envv)))
			return (envv);
		return (tmp);
	}
	else if (inf == 0)
	{
		if ((bin_path = check_bin(input, envv))
		&& (run_bin(bin_path, input, envv) > 0))
			free(bin_path);
		else if (!bin_path)
			error("command not found", NULL);
	}
	return (envv);
}

t_envv		*read_cmd(t_envv *envv, char *input)
{
	char **cmd;

	if (check_void_input(input))
		cmd = NULL;
	else if (!(cmd = ft_correct(ft_strsplit_word(input), envv)))
		error("impossible to parse input", NULL);
	ft_strdel(&input);
	if (!(envv = check_and_run_cmd(envv, cmd)))
		warning("something wrong happened", NULL);
	ft_freestrarr(cmd);
	return (envv);
}
