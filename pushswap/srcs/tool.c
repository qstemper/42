/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:26:50 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 15:01:41 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		valid_av(char **av)
{
	int		i;
	int		ret;
	char		*str;

	i = 0;
	ret = 0;
	while (av[++i])
	{
		ret = ft_atoi(av[i]);
		str = ft_itoa(ret);
		if (ft_strstr(av[i], str) == NULL)
			return (0);
	}
	return (1);
}

int			check_arg(char **av)
{
	int		i;
	int		j;

	j = 0;
	if (valid_av(av) == 0)
	{
		ft_fprintf(2, "Error\n");
		exit(1);
	}
	while (av[++j])
	{
		i = 0;
		if (av[j][i] != '-' && !ft_isdigit(av[j][i]))
			return (0);
		while (av[j][++i])
		{
			if (!ft_isdigit(av[j][i]))
				return (0);
		}
	}
	return (1);
}

void		destroy(t_stack a, t_stack b)
{
	free(a.tab);
	free(b.tab);
}
