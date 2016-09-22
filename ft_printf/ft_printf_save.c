#include "ft_printf.h"

void		save_buff(void *buff, size_t size)
{
	t_list	*cp;

	if (!size)
			return ;
	cp = ft_lstnew(buff, size);
	if (!cp)
			return ;
	ft_lstaddback(buff_list(), cp);
}
