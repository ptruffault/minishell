#include "libft.h"

static char	*my_strchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i--;
	}
	return (NULL);
}

static char	*split_name(char *path)
{
	char *ptr;
	char *ret;


	if (path[ft_strlen(path) - 1] == '/')
		path[ft_strlen(path) - 1] = '\0';

	if ((ptr = my_strchr(path, '/')))
	{
		*ptr++ = '\0';
		if (!(ret = ft_strdup(ptr)))
		{
			ft_putendl_fd("ft_ls : allocation failed", 2);
			exit (-1);
		}
	}
	else if ((ret = ft_strdup(path)))
	{
		path[0] = '.';
		path[1] = '\0';
	}
	else
	{
		ft_putendl_fd("ft_ls : allocation failed", 2);
		exit (-1);
	}
	return (ret);
}

static t_file *ft_find(t_file *file, char *name)
{
	t_file *prev;
	t_file *tmp;

	tmp = file;
	prev = ft_new_tfile();
	prev->next = tmp;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			ft_free_tfile(tmp->next);
			tmp->next = NULL;
			free(prev);
			return (tmp);
		}
		else
		{
			prev->next = tmp->next;
			ft_del_tfile(tmp);
			tmp = prev->next;
		}
	}
	free(prev);
	return (NULL);
}

t_file	*ft_search_tfile(char *path, int recursif)
{
	t_file *file;
	t_file *ret;
	char *name;

	name = split_name(path);
	file = ft_get_tfile(path, 0);
	if (!(ret = ft_find(file, name)))
	{
		ft_putendl_fd("ft_search_file : no such file or directory :", 2);
		ft_putendl_fd(name, 2);
		return (NULL);
	}
	if (ret->type == 'd')
		ret->sdir = ft_get_tfile(ret->path, recursif);
	free(name);
	return (ret);
}