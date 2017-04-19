/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:12:39 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/17 16:50:25 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(char) * size)) != NULL)
	{
		while ((int)size > -1)
		{
			str[size] = '\0';
			size--;
		}
		return (str);
	}
	return (NULL);
}
