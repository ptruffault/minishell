#include "../includes/minishell.h"
/*
static int	ft_putvar(char *str, int len, char **envv)
{
	char *var_name;
	char *var_value;

	if (!(var_name = ft_strnew(len + 1)))
		return (-1);
	var_name = ft_strncpy(var_name, str, len);
	var_name[len] = '\0';
	if (!(var_value = get_envv_var(envv, var_name)))
		return (-1);
	ft_putstr(var_value);
	free(var_name);
	return (0);
}

int	ft_echo(char **envv, char **input)
{
	int i;
	int j;
	char *ptr;
	int len;

	i = 1;
	while (input[i])
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			if (input[i][j] == '$' && input[i][j + 1] == '(' && 
				(ptr = ft_strchr(&input[i][j + 2], ')')))
			{
				len = ptr - &input[i][j] - 2;
				if (ft_putvar(&input[i][j + 2], len, envv) == -1)
					return (-1);
				j = j + 2 +len;
			}
			else
				ft_putchar(input[i][j++]);
		}
		i++;
		ft_putchar('\t');
	}
	ft_putchar('\n');
	return (0);
}*/