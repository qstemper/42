#include "ft_printf.h"

void	dlist_del(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*cp;

	while (*alst)
	{
		cp = (*alst)->n;
		dlist_delone(alst, del);
		*alst = cp;
	}
}
