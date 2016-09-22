#include "ft_printf.h"

void		dlist_add_ip(t_dlist **alst, t_dlist *elem, t_uint i)
{
	t_dlist	*cp;
	t_dlist	*tmp;

	cp = *alst;
	while (i-- && cp)
			cp = cp->n;
	if (!cp)
			*alst = elem;
	else
	{
		tmp = cp->p;
		cp->p = elem;
		elem->n = cp;
		elem->p = tmp;
		tmp->n = elem;
	}
}
