#include "libft.h"

char	*ft_strncut(char *str, int f)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < f)
	{
			i++;
			str++;
	}
	return (str);
}
