#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		if (str[i] > 47 && str[i] < 58)
			res = res * 10 + str[i];
		else
			return (0);
	}
	return (res);
}
