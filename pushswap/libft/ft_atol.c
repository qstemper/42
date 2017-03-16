#include "libft.h"

int	ft_atol(const char *str)
{
	long		res;
	size_t		i;
	unsigned int	neg;

	res = 0;
	i = 0;
	neg = 0;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg++;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	if (neg)
		return (-res);
	return (res);
}
