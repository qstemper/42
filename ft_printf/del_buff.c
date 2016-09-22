#include "ft_printf.h"

void	del_buff(t_buff **buff)
{
	if (!buff || !*buff)
			return ;
			if ((*buff)->buff)
					ft_memdel((void **)&(*buff)->buff);
			ft_memdel((void **)buff);
}
