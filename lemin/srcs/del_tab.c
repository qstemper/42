#include "lemin.h"

void		delete_tab(char ***tab)
{
	int			i;

	i = 0;
	while ((*tab)[i])
	{
		ft_memdel((void **)(*tab + i));
		++i;
	}
	ft_memdel((void **)tab);
}
