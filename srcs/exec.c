#include "../includes/minishell.h"

int		run_cmd(char *bin_path, char **envv, char **input)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(bin_path, input, envv);
	else if (pid < 0)
	{
		free(bin_path);
		ft_putendl_fd("minishell : Fork failed to create a new process.", 2);
		return (-1);
	}
	wait(&pid);
	if (bin_path)
		free(bin_path);
	return (1);
}