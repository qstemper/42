#include "libft.h"

void			ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist		*cp;

	while (*alst)
	{
		cp = (*alst)->n;
		ft_dlstdelone(alst, del);
		*alst = cp;
	}
}
