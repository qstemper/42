#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int	i;

	i = 0;
	if ((str = (char *)malloc(sizeof(char) * ft_strlen(s))) != NULL)
	{
		while (s[i] != '\0')
		{
			str[i] = f(i, ((char *)&s)[i]);
			i++;
		}
	}
	return (str);
}
