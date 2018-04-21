#include "libft.h"


//add static char **
//complétion ?
// gestion touches spéciales


char *ft_get_input(void)
{
	char *input;

	if (get_next_line(0, &input) == -1)
	{
		if (input)
			free(input);
		return (NULL);
	}
	return(input);
}