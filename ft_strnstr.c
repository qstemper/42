#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*ptr;
	int	i;

	if (s2 == '\0')
		return (s1);
	ptr = fr_strncmp(s1, s2);
	i = 0;
	while (s[i]!= '\0')
	{
		if (ptr == 0)
			return (ptr);
		i++;
	}
	return (NULL);
}
