#include "ft_printf.h"

int			del_darray2(t_darray2 *darray)
{
	t_uint	i;

	i = 0;
	while (i < darray->size)
	{
		if (darray->del)
				darray->del(darray->array[i]);
		free(darray->array[i]);
		i++;
	}
	free(darray->array);
	ft_bzero(darray, sizeof(t_darray2));
	return (1);
}
