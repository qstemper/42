/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 11:56:49 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/09 12:04:05 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	len;
	size_t	ite;

	len = ft_strlen(src);
	ite = 0;
	while (ite < length)
	{
		dest[ite] = src[ite];
		ite++;
	}
	dest[ite] = '\0';
	return (dest);
}
