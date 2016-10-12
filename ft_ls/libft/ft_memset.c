/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   sy: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 09:32:12 sy qstemper          #+#    #+#             */
/*   Updated: 2016/10/12 19:47:45 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	s+= (len - 1);
	while (len--)
	{
		*(t_uchar *)s = (t_uchar)c;
		if (len)
			s--;
	}
	return (s);
}
