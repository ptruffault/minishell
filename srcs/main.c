#include "../includes/minishell.h"

char	*get_cmd(char *input)
{
	char *cmd;
	int i;

	i = 0;
	while (IS_SPACE(*input))
		*input++;
	while (!(IS_SPACE(input[i])) && input[i] != '\0')
		i++;
	if (!(cmd = ft_strnew(i)))
		return (NULL);
	cmd = ft_strncpy(cmd, input, i);
	return (cmd);
}

int check_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "exit") == 0)
	{
		free(cmd);
		exit(0);
	}
	return (0);
}

int check_cmd(char *input)
{
	char *cmd;

	if (!(cmd = get_cmd(input)))
	{
		ft_putendl_fd("minishell : get_cmd failed", 2);
		return (0);
	}
	if (check_builtin(cmd) == 0)
		return (0);
	return (1);
}

int main(int argc, char **argv, char **env)
{
	char *input;

	while(1)
	{
		ft_putstr("\033[1;32mminishell >>\033[1;36m");
		if (!(input = ft_get_input()))
			ft_putendl_fd("minishell : ft_get_input failed", 2);
		else if (check_cmd(input) == 0)
			ft_putendl_fd("minishell : command not found", 2);
		if (input)
			free(input);
	}
}