/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmemcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 11:27:44 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/09 11:35:43 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfht.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
	}
	return (((unsigned char *)s1)[i - 1] - ((unsigned char *)s2)[i - 1]);
}
