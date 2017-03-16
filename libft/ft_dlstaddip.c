#include "libft.h"

void			ft_dlstaddip(t_dlist **alst, t_dlist *elem, t_uint i)
{
	t_dlist		*cp;
	t_dlist		*tmp;

	cp = *alst;
	while (i-- && cp)
		cp = cp->n;
	if (!cp)
		*alst = elem;
	else
	{
		tmp = cp->n;
		cp->p = elem;
		elem->n = cp;
		elem->p = tmp
		tmp->n = elem;
	}
}
