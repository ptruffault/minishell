#include "libft.h"

char	*ft_strndup(char *src, int len)
{
	char *new;
	int i;

	if (!(new = malloc(sizeof(char *) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len && src[i] != '\0')
	{
		new[i] = src [i];
		i++;
	}
	new[i] = '\0';
	return (new);
}