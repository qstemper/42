#include "ft_printf.h"

void		dlist_add_p(t_dlist **alst, t_dlist *elem)
{
	t_dlist	*cp;

	if (!*alst)
	{
		*alst = elem;
		return ;
	}
	cp = *alst;
	elem->n = cp;
	cp->p = elem;
	*alst = elem;
}
