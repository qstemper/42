/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 08:27:12 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/20 08:27:18 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		dump_room(void *meta)
{
	t_room	*r;

	r = (t_room *)meta;
	ft_printf(LEM_ROOM_DUMP_FMT, r->name, r->x, r->y);
}

void		dump_path(void *meta)
{
	t_path	*p;
	int		i;
	char	c;

	p = (t_path *)meta;
	ft_printf("\t{gr}[{eoc}");
	i = -1;
	while (++i < (int)p->size)
	{
		c = (i + 1 == (int)p->size ? ']' : ',');
		ft_printf(LEM_PATH_DUMP_FMT, p->step[i], c);
	}
	ft_printf("\n");
}

void		dump_graph(t_graph *g, char *name, void (*f)(void *))
{
	int		i;
	int		j;
	char	c;

	i = -1;
	ft_printf(LEM_GRAPH_DUMP_FMT, name);
	while (++i < (int)g->size)
	{
		ft_printf("{gr}%d{eoc} [", i);
		j = -1;
		while (++j < (int)g->node[i].neig_size)
		{
			c = (j + 1 == (int)g->node[i].neig_size ? ']' : ',');
			ft_printf("%d%c ", g->node[i].neig[j], c);
		}
		if (!j)
			ft_printf("]");
		ft_printf("\n");
		f(ACCESS_META(g, i));
	}
	ft_printf("\n");
}
