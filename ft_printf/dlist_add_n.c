#include "ft_printf.h"

void		dlist_add_n(t_dlist **alst, t_dlist *elem)
{
	t_dlist	*cp;

	if (!*alst)
	{
		*alst = elem;
		return ;
	}
	cp = *alst;
	while (cp->n)
			cp = cp->n;
	cp->n = elem;
	elem->p = cp;
}
