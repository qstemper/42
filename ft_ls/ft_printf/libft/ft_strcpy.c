/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 11:56:49 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/12 20:24:11 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	t_uint		i;

	if (!dest || !src)
		return (NULL);
	i = MAX_UINT;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
