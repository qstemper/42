/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 13:35:08 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/17 09:32:33 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	endstr;

	i = 0;
	while (dest[i] && i < size)
		i++;
	endstr = i;
	while (src[i - endstr] && i < size - 1)
	{
		dest[i] = src[i - endstr];
		i++;
	}
	if (endstr < size)
		dest[i] = '\0';
	return (endstr + ft_strlen(src));
}
