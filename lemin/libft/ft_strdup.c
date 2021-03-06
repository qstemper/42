/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 11:41:45 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/27 12:43:02 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_cpy;
	int		ite;

	ite = ft_strlen(s);
	if ((s_cpy = (char *)ft_memalloc(sizeof(char) * (ite + 1))) != NULL)
	{
		ft_memcpy(s_cpy, s, ite);
		return (s_cpy);
	}
	return (NULL);
}
