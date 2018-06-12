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

int	ft_unsetenv(t_envv *envv, char *name)
{
	t_envv *prev;

	prev = NULL;
	while (envv)
	{
		if (ft_strequ(envv->name, name))
		{
			if (prev != NULL)
				prev->next = envv->next;
			del_tenvv(envv);
			return (1);
		}
		prev = envv;
		envv = envv->next;
	}
	return (0);
}

t_envv	*ft_setenv(t_envv *envv, char *name, char *value)
{
	t_envv *new;
	t_envv *tmp;

	if ((tmp = get_tenvv(envv, name)))
	{
		if (!(envv = ft_changetenvv_val(envv, name, value)))
			return (NULL);
		return (envv);
	}
	if (!(new = new_tenvv())
	|| !(new->name = ft_strdup(name)) 
	|| !(new->value = ft_strdup(value)))
		return (NULL);
	new->next = envv;
	return (new);
}

void	ft_echo(char **input)
{
	int i;

	i = 0;
	while (input[i])
	{
		ft_putstr(input[i++]);
		ft_putchar('\t');
	}
	ft_putchar('\n');
}