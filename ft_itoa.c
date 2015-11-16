#include "libft.h"

static int	ft_nblen(int c)
{
	int	i;

	i = 0;
	if (c < 0 || c == 0)
	{
		c = -c;
		i++;
	}	
	while (c >= 1)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int	i;

	i = 0;
	if((str = (char *)malloc(sizeof(char) * ft_nblen(n)  + 1)) != NULL)
		return (NULL);
	if (n == 0)
	{
		str[i] = '0'
		i++;
	}
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	while (n >= 1)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
