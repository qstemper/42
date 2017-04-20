/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:16:14 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/20 07:49:48 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int c)
{
	int		i;

	i = 0;
	if (c == 0)
		i++;
	if (c < 0)
	{
		c = -c;
		i++;
	}
	while (c >= 1)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_nblen(n);
	str = NULL;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if ((str = (char *)ft_memalloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	if (n == 0)
		str[i - 1] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 1)
	{
		str[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
