#include "ft_printf.h"

void		dlist_delone(t_dlist **alst, void (*del)(void *, size_t))
{
	if (!*alst)
			return ;
	if (del)
			del((*alst)->content, (*alst)->content_size);
			ft_memdel((void **)alst);
}
