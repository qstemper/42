/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:08:44 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/17 16:49:23 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;

	if (s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strncmp(s1, s2, n) == 0)
			return ((char *)s1);
		i++;
	}
	return (NULL);
}
