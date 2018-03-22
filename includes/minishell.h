#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include "../libft/libft.h"

# define IS_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x == '\f')

char	**ft_init_envv(char **envv);
char	*get_envv_var(char **envv, char *str);
int 	check_cmd(char *input, char **envv);
int		run_cmd(char *bin_path, char **envv, char **input);
#endif
