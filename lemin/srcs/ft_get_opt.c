/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:02:00 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/06 13:02:02 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_getopt_arg(char *av, char *charset)
{
	char	*tmp;
	int		to;
	int		o;

	to = 0;
	while (*av)
	{
		tmp = charset;
		o = 1;
		while (*tmp)
		{
			if (*tmp == *av)
			{
				to += o;
				break ;
			}
			o <<= 1;
			++tmp;
		}
		++av;
	}
	return (to);
}

int			ft_getopt(int ac, char **av, char *charset)
{
	int		opt;
	int		j;

	opt = 0;
	j = 0;
	while (++j < ac)
	{
		if (av[j][0] != '-')
			break ;
		opt += ft_getopt_arg(av[j] + 1, charset);
	}
	return (opt);
}
