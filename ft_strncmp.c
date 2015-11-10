#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if((s[i] == '\0' || s2[i] == '\0') && n == 0)
		return (0);
	while (i < n && (s1[i] == s2[i]))
	{
		if ((s1[i] == '\0' && s2[i] != '\0') || \
				(s1[i] != '\0' && s2[i] == '\0'))
			return ((unsigned char *)s1 - (unsigned char *)s2);
		i++;
	}
	return ((unsigned char *)s1 - (unsigned char *)s2);
}
