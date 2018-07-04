/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:57:38 by ptruffau          #+#    #+#             */
/*   Updated: 2018/07/04 13:57:40 by ptruffau         ###   ########.fr       */
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
		ft_changetenvv_val(envv, "OLDPWD", cwd);
		ft_changetenvv_val(envv, "PWD", getcwd(buff, 4096));
	}
	else
	{
		if (access(path, F_OK) == -1)
			error("no such file or directory: ", path);
		else if (access(path, R_OK) == -1)
			error("permission denied: ", path);
		else
			error("not a directory: ", path);
		ft_putendl(path);
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
