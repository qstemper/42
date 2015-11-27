/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:08:44 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/26 18:41:04 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	len;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	while (s1[i] != '\0' && n > 0)
	{
		if (len <= n && ft_strncmp(s1 + i, s2, len) == 0)
			return ((char *)s1 + i);
		n--;
		i++;
	}
	return (NULL);
}
