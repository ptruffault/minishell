#include "../includes/minishell.h"

char *get_equal(char *name, char *value)
{
	char *tmp;
	char *ret;

	if (!(tmp = ft_strnew(ft_strlen(name) + 2)))
		return (NULL);
	tmp = ft_strcpy(tmp, name);
	tmp[ft_strlen(name)] = '=';
	tmp[ft_strlen(name) + 1] = '\0';
	if (!(ret = ft_strjoin(tmp, value)))
	{
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
