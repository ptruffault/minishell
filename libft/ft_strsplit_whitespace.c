#include "libft.h"

static int	ft_nw(char *s)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (IS_SPACE(s[i]))
		i++;
	while (s[i])
	{
		if (IS_SPACE(s[i]) && !(IS_SPACE(s[i - 1])))
			n++;
		i++;
	}
	if (!(IS_SPACE(s[i - 1])) && !s[i])
		n++;
	return (n);
}

static int	ft_lenword(char const *s, int i, int cstm)
{
	cstm = 0;
	while (!(IS_SPACE(s[i]) && s[i]))
	{
		cstm++;
		i++;
	}
	return (cstm);
}

static void	ft_j_loop(char const *s, char **new, int newindex)
{
	int j;

	j = -1;
	while (s[++j] && !(IS_SPACE(s[j])))
		new[newindex][j] = s[j];
	new[newindex][j] = '\0';
}

char		**ft_strsplit_whitespace(char const *s)
{
	int		cstm;
	int		i;
	char	**new;
	int		newindex;

	if (!s || !(new = (char **)malloc(sizeof(char*) * ft_nw((char *)s) + 1)))
		return (NULL);
	newindex = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && IS_SPACE(s[i]))
			i++;
		if (!s[i])
			break ;
		cstm = ft_lenword(s, i, cstm);
		new[newindex] = ft_strnew(cstm);
		if (!new[newindex])
			return (NULL);
		ft_j_loop(s + i, new, newindex++);
		i += cstm;
	}
	new[newindex] = NULL;
	return (new);
}