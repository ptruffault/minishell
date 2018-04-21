#include "../includes/minishell.h"

static char *ft_putvar(t_envv *envv, char *input)
{
	char *new;
	char *value;
	char *ptr;
	char *end;
	char *name;
	
	if ((ptr = ft_strchr(input, '$')) && *(ptr + 1) == '(' && (end = ft_strchr(input, ')'))
	&& !(name = ft_strnew((int)(end - ptr) - 2)))
		return (NULL);
	name = ft_strncpy(name, ptr + 2, (end - ptr) - 2);
	if (!(value = get_tenvv_val(envv, name))) 
	{
		ft_putstr_fd("minishell: no such envv var:", 2);
		ft_putendl_fd(name, 2);
		free(name);
		return (NULL);
	}
	if (!(new = ft_strpull(input, ptr, (end - ptr), value)))
	{
	 	free(name);
		return (NULL);
	}
	free(name);
	return (new);
}

static char **ft_corect(t_envv *envv, char **input)
{
	int i;
	int j;
	char *end;
	char *tmp;

	i = 0;
	while (input[i] != NULL)
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			if (input[i][j] == '$' && input[i][j + 1] == '(' && 
			(end = ft_strchr(&input[i][j + 3], ')')))
			{
				if (!(tmp = ft_putvar(envv, input[i])))
					return (NULL);
				j = j + (ft_strlen(tmp) - ft_strlen(input[i]));
				ft_strdel(&input[i]);
				input[i] = ft_strdup(tmp);
				free(tmp);
			}
			j++;
		}
		i++;
	}
	return (input);
}

char **ft_init_input(t_envv *envv, char *input)
{
	char **tmp;
	char **ret;

	if (!(tmp = ft_strsplit_word(input))
	|| !(ret = ft_corect(envv, tmp)))
	{
		free(input);
		if (tmp)
			ft_freestrarr(tmp);
		return (NULL);
	}
	free(input);
	return (ret);
}
