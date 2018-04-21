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

typedef struct s_envv	t_envv;
struct s_envv
{
	char	*name;
	char	*value;
	t_envv	*next;
};


char 	**ft_init_input(t_envv *envv, char *input);
void	init_tenvv(t_envv *envv, char **tab_envv);
int 	check_cmd(char *input, t_envv *envv);
char 	*check_bin(char **input, t_envv *envv);
int 	check_builtin(char **input);
int 	run_bin(char *path, char **args, t_envv *envv);
t_envv 	*run_builtin(char **input, t_envv *envv);
void	ft_cd(char **input, t_envv *envv);
t_envv 	*ft_setenv(t_envv *envv, char *name, char *value);
int 	ft_unsetenv(t_envv *envv, char *name);
t_envv 	*get_tenvv(t_envv *envv, char *name);
void	error(char *descrpt, char *name);
void	ft_puttenvv(t_envv *envv);
char 	**put_in_tab(t_envv *envv);
void	del_tenvv(t_envv *envv);
void	ft_free_tenvv(t_envv *envv);
t_envv	*new_tenvv(void);
t_envv 	*ft_changetenvv_val(t_envv *envv, char *name, char *new_val);
int 	envv_len(t_envv *envv);
char 	*get_tenvv_val(t_envv *envv, char *name);
char 	*get_value(char *equal);
char 	*get_name(char *equal);
char 	*get_equal(char *name, char *value);



#endif
