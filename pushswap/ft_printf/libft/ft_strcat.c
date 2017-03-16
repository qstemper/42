/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 12:44:51 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 10:42:00 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *s1, const char *s2)
{
	size_t		len;

	len = ft_strlen(s1);
	return (ft_strcpy(&s1[len], s2) - len);
}
