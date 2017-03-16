#include "libft.h"

void			ft_dlstaddp(t_dlist **alst, t_dlist *elem)
{
	t_dlist		*cp;

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
