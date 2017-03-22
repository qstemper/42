/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 09:47:33 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 09:49:53 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long				ft_atol(const char *str)
{
	size_t			i;
	long			res;
	unsigned int	neg;

	neg = 0;
	res = 0;
	i = 0;
	while (ft_isblank(str[i]) == 1)
		++i;
	if (str[i] == '-')
	{
		++i;
		++neg;
	}
	else if (str[i] == '+')
		++i;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	if (neg)
		return (-res);
	return (res);
}
