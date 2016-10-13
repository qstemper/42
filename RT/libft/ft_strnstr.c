/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:08:44 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/12 19:39:43 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;
	t_uint		i;

	i = MAX_UINT;
	if (!(len = ft_strlen(s2)))
		return ((char *)s1);
	while (len <= (n - ++i) && s1[i])
		if (!ft_strncmp(&s1[i], s2, len))
			return ((char *)&s1[i]);
	return (NULL);
}
