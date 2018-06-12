/* ***************************************************************************/
/*                                                                           */
/*                                                        :::      ::::::::  */
/*   ft_stradd_char.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2018/06/08 16:28:36 by ptruffau          #+#    #+#            */
/*   Updated: 2018/06/08 16:32:02 by ptruffau         ###   ########.fr       */
/*                                                                           */
/* ***************************************************************************/

#include "../includes/libft.h"

char	*ft_stradd_char(char *str, char c)
{
	char	*new;
	int		len;

	if (!(str))
	{
		if (!(str = ft_strnew(2)))
			return (NULL);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	len = ft_strlen(str);
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	new = ft_strcpy(new, str);
	new[len] = c;
	new[len + 1] = '\0';
	free(str);
	str = NULL;
	return (new);
}

