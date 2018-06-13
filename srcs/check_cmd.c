#include "../includes/minishell.h"


int		run_bin(char *path, char **args, t_envv *envv)
{
	pid_t	pid;
	char **arr;

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

static char	*check_exe(char *bin_path, struct stat inf)
{
	if (inf.st_mode & S_IFREG)
	{
		if (inf.st_mode & S_IXUSR)
			return (bin_path);
		else
		{
			error("permission denied", bin_path);
			free(bin_path);
		}
		return (NULL);
	}
	else
	{
		error("not an executable", bin_path);
		free(bin_path);
	}
	return (NULL);
}

char *local_try(char **input, t_envv *envv)
{
	char *path;
	struct stat		inf;

	path = ft_new_path(get_tenvv_val(envv, "PWD"), input[0]);
	if (lstat(path, &inf) == -1)
	{
		ft_strdel(&path);
		return (NULL);
	}
	else
		return (check_exe(path, inf));
}

char *check_bin(char **input, t_envv *envv)
{
	int				i;
	char			*bin_path;
	char			**path;
	struct stat		inf;

	path = NULL;
	if ((bin_path = local_try(input, envv)))
		return (bin_path);
	if (!(path = ft_strsplit(get_tenvv_val(envv, "PATH"), ':')))
		return (NULL);
	i = 0;
	while (path[i])
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
			return (check_exe(bin_path, inf));
		}
		i++;
	}
	ft_freestrarr(path);
	return (NULL);
}

