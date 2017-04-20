/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proginfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 08:30:47 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/20 08:30:50 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proginfo.h"

void					ft_skipopt(int ac, char **av, int *oac, char ***oav)
{
	int					i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
			continue ;
		break ;
	}
	*oac = ac - i;
	*oav = av + i;
}

t_proginfo				*proginfo(void)
{
	static t_proginfo	pi;

	return (&pi);
}

void					proginfo_init(int arg_c, char **arg_v,\
							char **env_p, char *opt_charset)
{
	t_proginfo			pi;

	ft_bzero((void *)&pi, sizeof(t_proginfo));
	pi.arg_c = arg_c;
	pi.arg_v = arg_v;
	pi.env_p = env_p;
	pi.name = arg_v[0];
	pi.opt = ft_getopt(arg_c, arg_v, opt_charset);
	ft_skipopt(arg_c, arg_v, &pi.oarg_c, &pi.oarg_v);
	*proginfo() = pi;
}

void					proginfo_destroy(void)
{
	ft_bzero((void *)proginfo(), sizeof(t_proginfo));
}
