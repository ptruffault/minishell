#include "../includes/minishell.h"

void	init_tenvv(t_envv *envv, char **tab_envv)
{
	int i;
	int len;
	t_envv *tmp;

	i = 0;
	tmp = envv;
	len = ft_strarrlen(tab_envv);
	while (i < len)
	{
		if (!(tmp->name = get_name(tab_envv[i])) 
		|| !(tmp->value = get_value(tab_envv[i])))
			return;
		i++;
		if (!(tmp->next = new_tenvv()))
			return;
		tmp = tmp->next;
	}
	tmp = NULL;
}

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

void	ft_disp(t_envv *envv, int argc, char **argv)
{
	if (argc != 1)
	{
		ft_putstr(argv[1]);
		ft_putchar('>');
	}
	else
	{
		ft_putstr("\033[1;32mminishell\033[00m:[\033[01;34m\033[04m");
		ft_putstr(get_tenvv_val(envv, "PWD"));
		ft_putendl("\033[00m]");
	}
}

int main(int argc, char **argv, char **envv)
{
	char *tmp;
	char **input;
	t_envv *my_envv;

	if (!(my_envv = new_tenvv()))
	{
		error("init envvironnement failure", "t_envv");
		return (-1);
	}
	init_tenvv(my_envv, envv);
	while(1)
	{
		ft_disp(my_envv, argc, argv);
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