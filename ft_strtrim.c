#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	int	i;
	int	j;

	len = ft_strlen(s);
	i = 0;
	j = 0;
	if ((str = (char *)malloc(sizeof(char) * len)) != NULL)
	{
		while (s[i] != '\0' && (s[i] = ' ' || s[i] = '\n' || s[i] = '\t'))
			i++;
		while (len != 0 && (s[l] = ' ' || s[l] = '\n' || s[l] = '\t'))
			l--;
		while (i < len)
		{
			str[j] = str[i];
			i++;
			j++;
		}
		return (str);
	}
	return (NULL);
}
