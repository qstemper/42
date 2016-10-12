/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 13:27:27 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/12 19:41:02 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		len;
	t_uint		i;

	i = MAX_UINT;
	len = ft_strlen(s1);
	while (n-- && s2[++i])
		s1[len++] = s2[i];
	s1[len] = '\0';
	return (s1);
}
