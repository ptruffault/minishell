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

static char	*ft_correct_one(t_envv *envv, char *s, char *ptr)
{
	char *ret;
	char *val;
	char *var_name;

	var_name = ft_get_next_word(ptr + 1);
	val = ft_strdup(get_tenvv_val(envv, var_name));
	ret = ft_strpull(s, ptr, ft_strlen(var_name), val);
	ft_strdel(&val);
	ft_strdel(&var_name);
	ft_strdel(&s);
	return (ret);
}

char	**ft_correct(char **input, t_envv *envv)
{
	int		i;
	char	*ptr;

	i = 0;
	while (input[i])
	{
		if ((ptr = ft_strchr(input[i], '$')) && !IS_SPACE(*(ptr + 1)))
			input[i] = ft_correct_one(envv, input[i], ptr);
		else if (input[i][0] == '~' && !input[i][1])
		{
			ft_strdel(&input[i]);
			input[i] = ft_strdup(get_tenvv_val(envv, "OLDPWD"));
		}
		else
			i++;
	}
	return (input);
}

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
	char	*bin_path;

	inf = check_builtin(input);
	if (inf == 1)
		return (run_builtin(input, envv));
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
	{
		ft_strdel(&input);
		return (envv);
	}
	else if (!(cmd = ft_correct(ft_strsplit_word(input), envv)))
		error("impossible to parse input", NULL);
	ft_strdel(&input);
	envv = check_and_run_cmd(envv, cmd);
	ft_freestrarr(cmd);
	return (envv);
}
