/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:28:58 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/05 10:29:37 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(char) * n + 1)) == NULL)
		return (NULL);
	ft_memcpy(str, s, n);
	str[n + 1] = '\0';
	return (str);
}
