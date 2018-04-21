#include "../includes/minishell.h"

// builtin :    cd  echo setenv  unset_env


// completion && UP 

t_envv *read_cmd(t_envv *envv, char **input)
 {
 	int inf;
 	t_envv *tmp;
 	char *bin_path;

 	inf = check_builtin(input);
	if (inf == 1)
	{
		if (!(tmp = run_builtin(input, envv)))
			return (envv);
		return (tmp);
	}
	else if (inf == 0)
	{
		if ((bin_path = check_bin(input, envv)) && (run_bin(bin_path, input, envv) > 0))
			free(bin_path);
		else if (!bin_path)
			error("command not found", NULL);
	}
	return (envv);
 }

 int exit_shell(char *str)
{
	ft_putendl_fd(str, 2);
	ft_putendl_fd("exit minishell", 2);
	return (0);
}


int main(int argc, char **argv, char **envv)
{
	char *tmp;
	char **input;
	t_envv *my_envv;

	if (argc != 1)
		ft_putstr(argv[1]);
	if (!(my_envv = new_tenvv()))
	{
		error("init envvironnement failure", "t_envv");
		return (-1);
	}
	init_tenvv(my_envv, envv);
	while(1)
	{
		ft_putstr("minishell> ");
		if (!(tmp = ft_get_input()))
			error("minishell : get_input failed", NULL);
		else if (!(input = ft_init_input(my_envv, tmp)))
			error("minishell : impossible to parse  input", NULL);
		if (!(my_envv = read_cmd(my_envv, input)))
		{
			error("minishell : envvironnement reloading", NULL);
			init_tenvv(my_envv, envv);
		}
		ft_freestrarr(input);
	}
	return(0);
}