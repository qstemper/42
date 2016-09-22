#include "ft_printf.h"

void		dump_darray2(t_darray2 *darray, void (f)(void *))
{
	t_uint	i;

	i = 0;
	while (i < darray->size)
	{
		if (f)
				f(darray->array[i]);
		i++;
	}
}
