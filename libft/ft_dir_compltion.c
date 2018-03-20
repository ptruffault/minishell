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
		ret = ft_strdup(ptr);
		return (ret);
	}
	else
	{
		ret = ft_strdup(path);
		if ((path))
			free(path);
		if (!(path = ft_strdup(".\0")))
		{
			ft_putendl_fd("ft_search_file : allocation failled", 2);
			return (NULL);
		}
		return (ret);
	}
}

static int 	test(char *name, char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (ft_strcmp(str, "*") == 0)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == '*')
		{
			while (name[j] != str[i + 1] && name[j] != '\0')
				j++;
			i++;
			if (name[j] == '\0' && str[i] != '\0')
				return (0);
			else if (name[j] == '\0')
				return (1);
		}
		if (str[i++] != name[j++])
			return (0);
	}
	return (1);
}

static void ft_sort(t_file *file, t_file *prev, char *str)
{
	while (file)
	{
		if (test(file->name, str) == 0)
		{
			prev->next = file->next;
			ft_del_tfile(file);
			file = prev->next;
		}
		else
		{
			prev = file;
			file = file->next;
		}
	}
}

t_file *ft_dir_compltion(char *str)
{
	t_file *head;
	t_file *file;
	t_file *prev;
	char *name;

	name = split_name(str);
	file = ft_new_tfile();
	prev = file;
	file->next = ft_get_tfile(str, 0);
	file = file->next;
	head = prev;
	ft_sort(file, prev, name);
	prev = head;
	head = head->next;
	free(prev);
	return (head);
}