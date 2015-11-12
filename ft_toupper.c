#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_islower(c) == 0)
		c = c - 32;
	return (c);
}
