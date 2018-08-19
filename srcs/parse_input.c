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

static char 		**ft_correct(char **input, t_envv *envv)
{
	int i;
	char *val;
	char *ptr;
	char *var_name;

	i = 0;
	while (input[i])
	{
		if((ptr = ft_strchr(input[i], '$')) && !IS_SPACE(*(ptr + 1))
		&& (var_name = ft_get_next_word(ptr + 1))) 
		{	
			if ((val = ft_strdup(get_tenvv_val(envv, var_name))))
			{
				input[i] = ft_strpull(input[i], ptr, ft_strlen(var_name), val);
				ft_strdel(&val);
			}
			else
				i++;
			ft_strdel(&var_name);
		}
		else
			i++;
	}
	return (input);
}

char		**ft_init_input(t_envv *envv, char *input)
{
	char **tmp;

	if (check_void_input(input))
	{
		ft_strdel(&input);
		return (NULL);
	}
	if (!(tmp = ft_correct(ft_strsplit_word(input), envv)))
	{
		ft_strdel(&input);
		error("impossible to parse input", NULL);
		return (NULL);
	}
	ft_strdel(&input);
	return (tmp);
}
