/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:15:47 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/17 16:44:45 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	i;
	int		j;

	len = ft_strlen(s);
	i = 0;
	j = 0;
	if ((str = (char *)malloc(sizeof(char) * len)) != NULL)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		while (len != 0 && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
			len--;
		while (i < len)
		{
			str[j] = str[i];
			i++;
			j++;
		}
		return (str);
	}
	return (NULL);
}
