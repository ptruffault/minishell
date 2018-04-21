#include "../includes/minishell.h"

t_envv	*new_tenvv(void)
{
	t_envv *new;

	if (!(new = (t_envv *)malloc(sizeof(t_envv))))
		return(NULL);
	new->next = NULL;
	new->name =NULL;
	new->value = NULL;
	return (new);
}

t_envv *ft_changetenvv_val(t_envv *envv, char *name, char *new_val)
{
	t_envv *tmp;

	tmp = envv;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
		{
			ft_strdel(&tmp->value);
			if (!(tmp->value = ft_strdup(new_val)))
				return (NULL);
			return (envv);
		}
		tmp = tmp->next;
	}
	error("no such envv var", name);
	return (envv);
}


void	init_tenvv(t_envv *envv, char **tab_envv)
{
	int i;
	int len;
	t_envv *tmp;

	i = 0;
	tmp = envv;
	len = ft_strarrlen(tab_envv);
	while (i < len)
	{
		if (!(tmp->name = get_name(tab_envv[i])) 
		|| !(tmp->value = get_value(tab_envv[i])))
			return;
		i++;
		if (!(tmp->next = new_tenvv()))
			return;
		tmp = tmp->next;
	}
	tmp = NULL;
}

void	del_tenvv(t_envv *envv)
{
	ft_strdel(&envv->name);
	ft_strdel(&envv->value);
	envv->next = NULL;
	free(envv);
}

void	ft_free_tenvv(t_envv *envv)
{
	t_envv *tmp;

	while(envv)
	{
		tmp = envv;
		envv = envv->next;
		del_tenvv(tmp);
	}
}

char **put_in_tab(t_envv *envv)
{
	char **tab;
	t_envv *tmp;
	int i;
	int len;

	i = 0;
	tmp = envv;
	len = envv_len(envv) - 1;
	if (!(tab = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	while (i < len)
	{
		if (!(tab[i++] = get_equal(tmp->name, tmp->value)))
			return (NULL);
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}

