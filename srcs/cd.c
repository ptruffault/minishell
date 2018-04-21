#include "../includes/minishell.h"


static void			change_dir(char *path, t_envv *envv)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		ft_changetenvv_val(envv, "OLDPWD", cwd);
		ft_changetenvv_val(envv, "PWD", getcwd(buff, 4096));
	}
	else
	{
		if (access(path, F_OK) == -1)
			error("cd : no such file or directory: ", NULL);
		else if (access(path, R_OK) == -1)
			error("cd : permission denied: ", NULL);
		else
			error("cd : not a directory: ", NULL);
		ft_putendl(path);
	}
}

void	ft_cd(char **input, t_envv *envv)
{
	if (!(input[1]))
		change_dir(get_tenvv_val(envv, "HOME"), envv);
	else if (input[1])
		change_dir(input[1], envv);
}

