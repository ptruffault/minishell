#include "../includes/minishell.h"

int	ft_unsetenv(t_envv *envv, char *name)
{
	t_envv *prev;

	prev = NULL;
	while (envv)
	{
		if (ft_strequ(envv->name, name))
		{
			if (prev != NULL)
				prev->next = envv->next;
			del_tenvv(envv);
			return (1);
		}
		prev = envv;
		envv = envv->next;
	}
	return (0);
}

t_envv	*ft_setenv(t_envv *envv, char *name, char *value)
{
	t_envv *new;

	if (!(new = new_tenvv())
	|| !(new->name = ft_strdup(name)) 
	|| !(new->value = ft_strdup(value)))
		return (NULL);
	new->next = envv;
	return (new);
}
