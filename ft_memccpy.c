/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 11:06:13 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/09 11:13:50 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_memccpy(void *dest, comct void *src, int c, size_t n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == ((unsigned char)c))
			return (dest);
		i++;
	}
	return (dest);
}
