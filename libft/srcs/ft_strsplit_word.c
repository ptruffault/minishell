#include "../includes/libft.h"

static int	ft_is_quote(char *str)
{
	char *ptr;

	if (*str == '"' || *str == '\'')
	{
		if ((ptr = ft_strchr(str + 1, *str)))
			return (1);
		return (-1);
	}
	return (0);
}

static int word_len(char *str)
{
	int ret;
	int i;

	ret = ft_is_quote(str);
	i = 0;
	if (ret == -1)
	{
		ft_putendl_fd("minishell : invalid quote : missing end symbol  :", 2);
		ft_putendl_fd(str, 2);
		return (-1);
	}
	if (ret == 0)
	{
		while (!(IS_SPACE(str[i])) && str[i] != '\0')
			i++;
		return (i);
	}
	if (ret == 1)
		return (ft_strchr(str + 1, *str) - (str + 1));
	return (-1);
}

static int	ft_nb_w(char *str)
{
	int i;
	int n;
	char *ptr;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (!(IS_SPACE(str[i])))
		{
			if ((str[i] == '"' || str[i] == '\'') && (ptr = ft_strchr(&str[i + 1], str[i])))
				i = i + (ptr - &str[i]);
			else
			{
				while (!(IS_SPACE(str[i])) && str[i] != '\0')
					i++;
			}
			n++;
		}
		if (str[i] != '\0')
			i++;
	}
	return (n);
}

static char	*get_next_word(char *str)
{
	char *word;
	int len;

	if ((len = word_len(str)) == -1)
		return (NULL);
	if (!(word = ft_strnew(len)))
		return (NULL);
	if (ft_is_quote(str))
		word = ft_strncpy(word, str + 1, len);
	else 
		word = ft_strncpy(word, str, len);
	return (word);
}


char **ft_strsplit_word(char *str)
{
	char **tab;
	int len;
	int k;
	int i;

	if ((len = ft_nb_w(str)) <= 0)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	k = 0;
	i = 0;
	while (str[i])
	{
		if (!(IS_SPACE(str[i])))
		{
			if (!(tab[k++] = get_next_word(&str[i])))
			{
				ft_freestrarr(tab);
				return (NULL);
			}
			i = i + word_len(&str[i]) + 2 * ft_is_quote(&str[i]);
		}
		else
			i++;
	}
	tab[k] = NULL;
	return (tab);
}