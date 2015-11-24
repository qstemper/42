/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 12:05:24 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/17 16:50:57 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	ite;

	len = ft_strlen(src);
	ite = 0;
	if (len > n)
	{
		while (ite < n)
		{
			dest[ite] = src[ite];
			ite++;
		}
	}
	else
	{
		while (ite < len)
		{
			dest[ite] = src[ite];
			ite++;
		}
		ft_bzero((void *)(dest + ite), n - ite);
	}
	return (dest);
}
