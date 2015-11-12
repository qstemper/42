#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int	i;
	
	i = 0;
	if ((ptr = (char *)malloc(sizeof(char) * len)) != NULL)
	{
		while(i < len)
		{
			ptr[i] = s[start + i];
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
