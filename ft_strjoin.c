#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))) != NULL)
	{
		str = ft_strcat(s1, s2);
		str[len1 + len2 = 1] = '\0';
		return (str);
	}
	return (NULL);
}
