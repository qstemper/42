/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 12:05:24 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/12 20:58:32 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	t_uint	i;

	i = MAX_UINT;
	while (++i < n && src[i])
		dest[i] = src[i];
	ft_bzero((void *)&dest[i], n - 1);
		return (dest);
}
