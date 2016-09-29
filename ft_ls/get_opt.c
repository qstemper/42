/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:00:10 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/29 13:21:52 by qstemper         ###   ########.fr       */
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
	return (0_PRIVATE_ERROR);
}

int			get_opt(const char *cdet, int ac, char **av, char **err)
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
			o |= get_solo_opt(charset, av[i][j], err);
	}
	return (o);
}
