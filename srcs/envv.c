#include "../includes/minishell.h"

static int		envv_len(char **envv)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (envv[++i])
		count++;
	return (count);
}

char	*get_envv_var(char **envv, char *str)
{
	int		i;

	i = 0;
	while (envv[i])
	{
		if (ft_str_startwith(envv[i], str) 
			&& envv[i][ft_strlen(str)] == '=')
			return (ft_strchr(envv[i], '=') + 1);
		i++;
	}
	ft_putstr_fd("minishell : there is no such envvironement variable: ", 2);
	ft_putendl_fd(str, 2);
	return (NULL);
}

char	**ft_init_envv(char **envv)
{
	char **new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (envv_len(envv) + 1));
	i = 0;
	while (envv[i])
	{
		if (!(new[i] = ft_strdup(envv[i])))
		{
			ft_putstr_fd("minishell : init_envv allocation failed ", 2);
			ft_freestrarr(new);
			exit(-1);
		}
		i++;
	}
	return (new);
}