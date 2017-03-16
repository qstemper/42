#include "libft.h"

void			ft_dlstaddn(t_dlist **alst, t_dlist *elem)
{
	t_dlist		*cp;

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
