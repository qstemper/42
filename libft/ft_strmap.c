/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:14:33 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/26 15:22:55 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if ((str = (char *)malloc(sizeof(char) * ft_strlen(s))) != NULL)
	{
		while (s[i] != '\0')
		{
			str[i] = f(((char *)&s)[i]);
			i++;
		}
	}
	return (NULL);
}
