#include "libft.h"

void	ft_putstr_color_fd(char *str, char *color , int fd)
{
	char *color_str;

	color_str = ft_strjoin(color, str);
	ft_putstr_fd(color_str, fd);
	free(color_str);
	ft_putstr_fd(NORMAL, fd);
}

void	ft_putstr_color(char *str , char *color)
{
	ft_putstr_color_fd(str, color, 1);
}