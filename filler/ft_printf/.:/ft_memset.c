/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 13:17:10 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 13:17:25 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	s += (len - 1);
	while (len--)
	{
		*(t_uchar *)s = (t_uchar)c;
		if (len)
			s--;
	}
	return (s);
}
