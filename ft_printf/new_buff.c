#include "ft_printf.h"

t_buff		*new_buff(int fd, size_t buff_size)
{
	t_buff	*new;

	if (!(new = (t_buff *)malloc(sizeof(t_buff))))
			return (NULL);
	new->ret = 0;
	new->fd = fd;
	new->buff_size = buff_size;
	if (!(new->buff = ft_strnew(buff_size)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}
