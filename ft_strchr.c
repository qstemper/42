/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 14:07:08 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/09 14:18:23 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(cont char *s, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}
