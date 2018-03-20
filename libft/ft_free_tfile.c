#include "libft.h"

void	ft_del_tfile(t_file *file)
{
	if (file->type == 'l' && (file->link))
		free(file->link);
	if ((file->name))
		free(file->name);
	if ((file->owner))
		free(file->owner);
	if ((file->group))
		free(file->group);
	if ((file->mode))
		free(file->mode);
	if ((file->path))
		free(file->path);
	file->next = NULL;
	file->sdir = NULL;
	free(file);
}

void			ft_free_tfile(t_file *file)
{
	t_file *tmp;

	while (file)
	{
		tmp = file->next;
		if (file->type == 'd' && (file->sdir))
			ft_free_tfile(file->sdir);
		ft_del_tfile(file);
		file = tmp;
	}
}