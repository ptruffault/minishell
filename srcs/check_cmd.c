#include "../includes/minishell.h"

static int check_builtin(char **input, char **envv)
{
	if (ft_strequ(input[0], "exit"))
	{
		free(input[0]);
		ft_putendl("\033[00;31mminishell stoped\033[00m");
		exit(0);
	}
	else if (ft_strequ(input[0], "env"))
		ft_putstr_tab(envv);
	else
		return (0);
	return (1);
}

static int		check_exe(char *bin_path, struct stat inf, char **envv, char **input)
{
	if (inf.st_mode & S_IFREG)
	{
		if (inf.st_mode & S_IXUSR)
			return (run_cmd(bin_path, envv, input));
		else
		{
			ft_putstr("minishell: permission denied: ");
			ft_putendl(bin_path);
		}
		free(bin_path);
		return (1);
	}
	free(bin_path);
	return (0);
}

static int 	check_bin(char **input, char **envv)
{
	int				i;
	char			*bin_path;
	char			**path;
	struct stat		inf;

	path = ft_strsplit(get_envv_var(envv, "PATH"), ':');
	i = 0;
	while (path && path[i])
	{
		if (ft_str_startwith(input[0], path[i]))
			bin_path = ft_strdup(input[0]);
		else
			bin_path = ft_new_path(path[i], input[0]);
		if (lstat(bin_path, &inf) == -1)
			free(bin_path);
		else
		{
			ft_freestrarr(path);
			return (check_exe(bin_path, inf, envv, input));
		}
		i++;
	}
	ft_freestrarr(path);
	return (0);
}

int check_cmd(char *str, char **envv)
{
	char **input;

	if (!(input = ft_strsplit_whitespace(str)))
	{
		ft_putendl_fd("minishell : get_cmd failed", 2);
		return (0);
	}
	ft_putstr_tab(input);
	if (check_builtin(input, envv) == 0 && check_bin(input, envv) == 0)
		return (0);
	return (1);
}