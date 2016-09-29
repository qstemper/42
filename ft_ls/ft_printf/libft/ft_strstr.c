/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 14:24:12 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/26 10:18:21 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	size_t	len;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	while (s1[i] != '\0')
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
