#include "libft.h"

char *ft_get_input(void)
{
	int ret;
	char buff;
//	char *tmp;
	char *input;
	int i;

	if (!(input = ft_strnew(1)))
	{
		ft_putendl_fd("ft_get_input : allocation failure", 2);
		return (NULL);
	}
	i = 0;
	while ((ret = read(0, &buff, 1)) && buff != '\n')
	{
		ft_putnbr(buff);
	/*	if (buff == '^[OP')
		{
			tmp = ft_strjoin(input, "*");
			ft_put_tfile(ft_dir_compltion(tmp));
			free(tmp);
		}
		else
		{*/
			input[i++] = buff;
			input = ft_realloc(input, i, i + 1);
		//}
	}
	input[i] = '\0';
	if (!ret)
	{
		free(input);
		ft_putendl_fd("ft_get_input : read() failure", 2);
		return (NULL);
	}
	return(input);
}
