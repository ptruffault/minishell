#include "../includes/libft.h"

char		*ft_get_next_word(char *str)
{
	char	*word;
	int		j;

	j = 0;
	word = NULL;
	while (IS_SPACE(str[j]))
		j++;
	while (!(IS_SPACE(str[j])) && str[j] != '\0')
		j++;
	if (!(word = ft_strnew(j)))
	{
		error("allocation failed", "ft_strsplit_whitespace");
		return (NULL);
	}
	word = ft_strncpy(word, str, j);
	return (word);
} 
