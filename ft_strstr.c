/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 14:24:12 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/09 15:11:04 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*ptr;
	int	i;

	if (s2 == '\0')
		return (s1);
	ptr = fr_strcmp(s1, s2);
	i = 0;
	while (s[i]!= '\0')
	{
		if (ptr == 0)
			return (ptr);
		i++;
	}
	return (NULL);
}
