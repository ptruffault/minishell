#include "../includes/minishell.h"

int ft_strarrlen(char **arr)
{
	int i;

	i = 0;
	while ((arr[i]))
		i++;
	return (i);
}