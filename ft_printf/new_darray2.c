#include "ft_printf.h"

int		new_darray2(t_darray2 *darray, size_t size, t_darray_del del)
{
	ft_bzero((void *)darray, sizeof(t_darray2));
	darray->array = (void **)ft_memalloc(sizeof(void *) * DARRAY2_OFFSET);
	if (!darray->array)
			return (1);
	darray->size_content = size;
	darray->size_max = DARRAY2_OFFSET;
	if (del)
			darray->del = del;
	return (0);
}
