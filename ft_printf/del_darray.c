#include "ft_printf.h"

void	del_darray(t_darray *array)
{
	free(array->data);
	free(array->address);
	ft_bzero((void *)array, sizeof(t_darray));
}
