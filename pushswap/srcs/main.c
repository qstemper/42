/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:46:52 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 16:28:09 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			main(int ac, char **av)
{
	char	e;
	int		skip;
	int		o;

	e = 0;
	o = get_opt(CSET_O, ac, av, &e);
	if (IS(O_DEBUG, o))
		debug_o(o);
	if (IS(O_PRIVATE_ERROR, o))
		return (usage(av[0], e, EXIT_FAILURE, o));
	skip = go_over_opt(ac, av);
	av += skip;
	if (!(ac -= skip))
		return (EXIT_SUCCESS);
	return (pushswap(ac, av, o));
}
