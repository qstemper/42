#include "lemin.h"

void		dump_room(void *meta)
{
	t_room	*r;

	r = (t_room *)meta;
	ft_printf("\t{gr|cyan}%s{eoc}: ({blue}%d{eoc}, {red}%d{eoc})", \
			r->name, r->x, r->y);
}

void		dump_path(void *meta)
{
	t_path	*p;
	int	i;

	p = (t_path *)meta;
	ft_printf("\t{gr}[{eoc}");
	i = -1;
	while (++i < p->size)
	{
		ft_printf("{gr|cyan}%d{eoc}{gr}%c{eoc}", p->step[i], \
			(i + 1 == p->size ? ']' : ','));
	}
}


void		dump_graph(t_graph *g, char *name, void (*f)(void *))
{
	int	i;
	int	j;

	i = -1;
	ft_printf("{gr|ss}Dumping graph \
			`{eoc}{gr|ss|green}%s{eoc}{gr|ss}`{eoc}\n\n", name);
	while (++i < g->size)
	{
		f(g->node[i].meta);
		ft_printf("\t{gr}%d{eoc} [", i);
		j = -1;
		while (++j < g->node[i].neig_size)
			ft_printf("%d%c ", g->node[i].neig[j], \
			(j + 1 == g->node[i].neig_size ? ']' : ','));
		if (!j)
			ft_printf("]");
		ft_printf("\n");
	}
	ft_printf("\n");
}
