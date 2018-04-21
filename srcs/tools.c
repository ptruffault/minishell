#include "../includes/minishell.h"

void	error(char *descrpt, char *name)
{
	ft_putstr_fd("\033[00;31mminishell : \033[00m", 2);
	ft_putstr_fd(descrpt, 2);
	if (name)
	{
		ft_putstr_fd(" : '\033[1;32m", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd("\033[00m'", 2);
	}
	ft_putchar_fd('\n', 2);
}

char *get_equal(char *name, char *value)
{
	char *tmp;
	char *ret;

	if (!(tmp = ft_strnew(ft_strlen(name) + 2)))
	{
		error("get_equal , allocation failed", NULL);
		return (NULL);
	}
	tmp = ft_strcpy(tmp, name);
	tmp[ft_strlen(name)] = '=';
	tmp[ft_strlen(name) + 1] = '\0';
	if (!(ret = ft_strjoin(tmp, value)))
	{
		error("get_equal , ft_strjoin failed", NULL);
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (ret);
}


char *get_name(char *equal)
{
	int i;
	char *name;
	
	i = 0;
	while (equal[i] != '=')
	{
		if (equal[i++] == '\0')
			return(NULL);
	}
	if (!(name = ft_strnew(i)))
		return (NULL);
	name = ft_strncpy(name, equal, i);
	name[i + 1] = '\0';
	return (name);
}

char *get_value(char *equal)
{
	char *ptr;
	char *value;

	if (!(ptr = ft_strchr(equal, '=') + 1)
		|| !(value = ft_strdup(ptr)))
		return (NULL);
	return (value);
}

char *get_tenvv_val(t_envv *envv, char *name)
{
	while (envv)
	{
		if (ft_strequ(name, envv->name))
			return (envv->value);
		envv = envv->next;
	}
	return (NULL);
}

int envv_len(t_envv *envv)
{
	t_envv *tmp;
	int i;

	i = 0;
	tmp = envv;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int ft_strarrlen(char **arr)
{
	int i;

	i = 0;
	while ((arr[i]))
		i++;
	return (i);
}

void	ft_puttenvv(t_envv *envv)
{
	t_envv *tmp;

	tmp = envv;
	while (tmp != NULL)
	{
		ft_putstr("\033[04m");
		ft_putstr(tmp->name);
		ft_putstr("\033[00m = \033[1;32m");
		ft_putendl(tmp->value);
		ft_putstr("\033[00m");
		tmp = tmp->next;
	}
}
