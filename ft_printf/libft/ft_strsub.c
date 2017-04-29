/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:15:26 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/26 13:16:46 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if ((ptr = (char *)ft_memalloc(sizeof(char) * (len + 1))) != NULL)
	{
		while (i < len)
		{
			ptr[i] = s[start + i];
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
