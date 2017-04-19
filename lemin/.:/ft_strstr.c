/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 14:24:12 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/12 19:39:07 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	size_t		len;
	t_uint		i;

	i = MAX_UINT;
	if (!(len = ft_strlen(s2)))
		return ((char *)s1);
	while (s1[++i])
		if (!ft_strncmp(&s1[i], s2, len))
			return ((char *)&s1[i]);
	return (NULL);
}
