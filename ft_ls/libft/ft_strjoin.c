/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:15:37 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 17:24:03 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))) != NULL)
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		str[len1 + len2 + 1] = '\0';
		return (str);
	}
	return (NULL);
}
