/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 13:27:27 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/09 14:06:59 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*temp;
	size_t	i;

	temp = s1 + ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0' && n != 0)
	{
		temp[i] = s2[i];
		i++;
		n--;
	}
	return (s1);
}
