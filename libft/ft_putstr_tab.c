#include "libft.h"

void	ft_putstr_tab(char **tab)
{
	int i;

	i = 0;
	while ((tab[i]))
		ft_putendl(tab[i++]);
}
