#include "ft_printf.h"

static void	array_majaddr(t_darray *array)
{
	size_t	i;
	void	*tmp;

	i = 0;
	tmp = array->data;
	while (i < array->i)
	{
		array->address[i].data = tmp;
		tmp += array->address[i].size;
		i++;
	}
}

static int	init_array(t_darray *array, size_t size)
{
	array->data = ft_memalloc(size * 2);
	if (!array->data)
			return (1);
	array->address = (t_cel *)ft_memalloc(sizeof(t_cel) * 2);
	if (!array->address)
	{
		free(array->data);
		return (1);
	}
	array->curr = array->data;
	array->end = array->curr + (size * 2);
	array->size = 2;
	return (0);
}

static int	array_expdata(t_darray *array)
{
	void	*tmp;
	size_t	size;

	tmp = array->data;
	size = array->end - array->data;
	array->data = ft_memalloc(size * 2);
	if (!array->data)
	{
		free(tmp);
		free(array->address);
		return (0);
	}
	ft_memcpy(array->data, tmp, size);
	array->curr = array->data + (array->curr - tmp);
	array->end = array->data + (size * 2);
	free(tmp);
	array_majaddr(array);
	return (1);
}

static int	array_expcel(t_darray *array)
{
	t_cel	*tmp;

	tmp = array->address;
	array->address = (t_cel *)ft_memalloc((sizeof(t_cel) * array->size) * 2);
	if (!array->address)
	{
		free(tmp);
		free(array->data);
		return (0);
	}
	ft_memcpy(array->address, tmp, (sizeof(t_cel) * array->size));
	array->size *= 2;
	free(tmp);
	return (1);
}

int			add_darray(t_darray *array, void *data, size_t size)
{
	if (!array->size)
	{
		if (init_array(array, size))
				return (1);
	}
	else
	{
		while ((size + array->curr) > array->end)
		{
			if (!array_expdata(array))
					return (1);
		}
		if (array->size && array->i >= array->size && !array_expcel(array))
				return (1);
	}
	array->address[array->i].data = array->curr;
	array->address[array->i].size = size;
	ft_memcpy(array->curr, data, size);
	array->curr += size;
	array->i++;
	return (0);
}
