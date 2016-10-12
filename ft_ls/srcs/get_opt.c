/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:00:10 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/06 11:04:03 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_solo_opt(const char *charset, char c, char *e)
{
	int		o;

	o = 0x1;
	while (*charset)
	{
		if (*charset++ == c)
			return (o);
		o <<= 0x1;
	}
	if (!*e)
		*e = c;
	return (O_PRIVATE_ERROR);
}

int			get_opt(const char *cset, int ac, char **av, char *err)
{
	int		i;
	int		j;
	int		o;

	i = 0;
	o = 0x0;
	while (++i < ac)
	{
		if ((av[i][0] != '-') || (ft_strlen(av[i]) == 1))
			break ;
		j = 0;
		while (av[i][++j])
			o |= get_solo_opt(cset, av[i][j], err);
	}
	return (o);
}
