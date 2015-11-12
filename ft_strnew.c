#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(char) * size)) != NULL)
	{
		while (size >= 0)
		{
			str[size] = '\0';
			size --;
		}
		return (str);
	}
	return (NULL);
}
