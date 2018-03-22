#include "../includes/minishell.h"

// argv -> exe_cmd
  
 //  (REPARER FT_STR_SPLIT_WHITESPACES)



// builtin :    cd  echo setenv  unset_env




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