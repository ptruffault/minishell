#include "libft.h"

void	ft_put_tfile(t_file *file)
{
	while (file)
	{
		ft_putendl(file->name);
		file = file->next;
	}
}
