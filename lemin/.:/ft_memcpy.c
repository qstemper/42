/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 10:47:12 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/12 19:29:53 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*cp;

	cp = dest;
	while (n--)
	{
		*(t_uchar *)dest = *(t_uchar*)src;
		dest++;
		src++;
	}
	return (cp);
}
