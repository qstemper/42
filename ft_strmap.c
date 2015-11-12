#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int	i;

	i = 0;
	if ((str = (char *)malloc(sizeof(char) * ft_strlen(s))) != NUL)
	{
		while (s[i] != '\0')
		{
			str[i] = f(((char *)&s)[i]);
			i++;
		}
	}
	return (str);
}
