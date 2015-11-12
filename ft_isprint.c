#include "libft.h"

int	ft_isprint(int c)
{
	if (ft_isascii(c) == 0 || c == 32)
		return (0);
	return (1);
}
