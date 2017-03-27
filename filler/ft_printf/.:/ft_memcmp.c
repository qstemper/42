/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmemcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 11:27:44 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 13:16:44 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n-- && *(t_uchar *)s1 == *(t_uchar *)s2)
	{
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return (*(t_uchar *)s1 - *(t_uchar *)s2);
}
