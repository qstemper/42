/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:41:28 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 09:49:54 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isblank(char c)
{
	if (c == '\n' || c == '\t' || c == ' ' || c == '\r' || \
			c == '\f' || c == '\v')
		return (1);
	return (0);
}
