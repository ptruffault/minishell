#include "libft.h"

char	*ft_caps_lock(char *str)
{
	int i;
	char *new;

	i = 0;
	if (!(new = ft_strdup(str)))
		return (NULL);
	while (new[i] != '\0')
	{
		if ( 97 <= new[i] && new[i] <= 122)
			new[i] = new[i] - 32;
		i++; 
	}
	return (new);
}
