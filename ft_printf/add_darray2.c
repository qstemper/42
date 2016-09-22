#include "ft_printf.h"

static int	safe_add_darray2(t_darray2 *darray, void *data)
{
	void	*cp;

	cp = ft_memalloc(darray->size_content);
	if (!cp)
			return (del_darray2(darray));
	ft_memcpy(cp, data, darray->size_content);
	darray->array[darray->size++] = cp;
	return (0);
}

static int	exp_darray2(t_darray2 *darray, void *data)
{
	void	**tmp;

	tmp = darray->array;
	darray->array = ft_memalloc(sizeof(void *) * (darray->size_max * 2));
	if (!darray->array)
	{
		darray->array = tmp;
		return (del_darray2(darray));
	}
	ft_memcpy(darray->array, tmp, darray->size_max * sizeof(void *));
	free(tmp);
	darray->size_max *= 2;
	return (safe_add_darray2(darray, data));
}

int			add_darray2(t_darray2 *darray, void *data)
{
	if(darray->size < darray->size_max)
			return (safe_add_darray2(darray, data));
	else
			return (exp_darray2(darray, data));
	return(0);
}
