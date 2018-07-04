/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:11:19 by ptruffau          #+#    #+#             */
/*   Updated: 2018/07/04 14:11:20 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_putvar(t_envv *envv, char *input)
{
	char *new;
	char *value;
	char *ptr;
	char *end;
	char *name;

	name = NULL;
	end = NULL;
	if ((ptr = ft_strchr(input, '$')) && *(ptr + 1) == '('
	&& (end = ft_strchr(input, ')'))
	&& !(name = ft_strnew((int)(end - ptr) - 2)))
		return (NULL);
	name = ft_strncpy(name, ptr + 2, (end - ptr) - 2);
	if (!(value = get_tenvv_val(envv, name))
	|| !(new = ft_strpull(input, ptr, (end - ptr), value)))
	{
		free(name);
		return (NULL);
	}
	free(name);
	return (new);
}

static void	ft_norme(char *tmp, char **input, int i, int *j)
{
	*j = *j + (ft_strlen(tmp) - ft_strlen(input[i]));
	ft_strdel(&input[i]);
	input[i] = ft_strdup(tmp);
	ft_strdel(&tmp);
}

static char	**ft_corect(t_envv *envv, char **input)
{
	int		i;
	int		j;
	char	*end;
	char	*tmp;

	i = -1;
	while (input[++i] != NULL)
	{
		j = -1;
		while (input[i][j++] != '\0')
		{
			if (input[i][j] == '$' && input[i][j + 1] == '(' &&
			(end = ft_strchr(&input[i][j + 3], ')')))
			{
				if (!(tmp = ft_putvar(envv, input[i])))
				{
					ft_freestrarr(input);
					return (NULL);
				}
				ft_norme(tmp, input, i, &j);
			}
		}
	}
	return (input);
}

int			check_void_input(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
		if (!IS_SPACE(s[i++]))
			return (0);
	return (1);
}

char		**ft_init_input(t_envv *envv, char *input)
{
	char **tmp;

	if (check_void_input(input))
		return (NULL);
	if (!(tmp = ft_corect(envv, ft_strsplit_word(input))))
	{
		free(input);
		error("impossible to parse  input", NULL);
		return (NULL);
	}
	free(input);
	return (tmp);
}
