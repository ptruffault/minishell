#include "../includes/minishell.h"

char	*get_cmd(char *input)
{
	char *cmd;
	int i;
	int j;

	i = 0;
	j = 0;
	while (IS_SPACE(input[j]))
		j++;
	while (!(IS_SPACE(input[j + i])) && input[j + i] != '\0')
		i++;
	if (!(cmd = ft_strnew(i)))
		return (NULL);
	cmd = ft_strncpy(cmd, &input[j], i);
	return (cmd);
}

int check_builtin(char *cmd, char **envv)
{
	if (ft_strequ(cmd, "exit"))
	{
		free(cmd);
		ft_putendl("\033[00;31mminishell stoped\033[00m");
		exit(0);
	}
	else if (ft_strequ(cmd, "env"))
		ft_putstr_tab(envv);
	else
		return (0);
	return (1);
}

int 	check_bin(char *cmd, char **envv)
{
	int				i;
	char			*bin_path;
	char			**path;
	struct stat		f;

	path = ft_strsplit(get_env_var(envv, "PATH"), ':');
	i = 0;
	while (path && path[i])
	{
		if (ft_strstartswith(cmd, path[i]))
			bin_path = ft_strdup(cmd);
		else
			bin_path = ft_new_path(path[i], cmd);
		if (lstat(bin_path, &f) == -1)
			free(bin_path);
		else
		{
			ft_freestrarr(path);
			return (is_executable(bin_path, f, cmd));
		}
		i++;
	}
	ft_freestrarr(path);
	return (0);
}

int check_cmd(char *input, char **envv)
{
	char *cmd;

	if (!(cmd = get_cmd(input)))
	{
		ft_putendl_fd("minishell : get_cmd failed", 2);
		return (0);
	}
	if (check_builtin(cmd, envv) == 0 || check_bin(cmd, envv) == 0)
		return (0);
	return (1);
}



int main(int argc, char **argv, char **envv)
{
	char *input;
	char **my_envv;

	if (argc != 1)
		ft_putstr(argv[1]);
	my_envv = ft_init_envv(envv); 
	while(1)
	{
		ft_putstr("\033[1;32mminishell >>\033[00m");
		if (!(input = ft_get_input()))
			ft_putendl_fd("minishell : ft_get_input failed", 2);
		else if (check_cmd(input, my_envv) == 0)
			ft_putendl_fd("minishell : command not found", 2);
		if (input)
			free(input);
	}
}