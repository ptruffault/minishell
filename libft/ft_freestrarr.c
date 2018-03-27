#include "libft.h"

void	ft_freestrarr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = 0;
	while ((arr[i]))
		free(arr[i++]);
	free(arr);
	arr = NULL;
}