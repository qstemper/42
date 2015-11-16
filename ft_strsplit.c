#include "libft.h"

static int	ft_count_parts(char const *s, char c)
{
	int	cmpt;
	int	var;
	int	i;

	cmp = 0;
	var = 0;
	while (s[i] != '\0')
	{
		if (var == 0 && s[i] != c)
		{
			var = 1;
			cmp++;
		}
		if (var == 1 && s[i] == c)
			var = 0;
		i++;
	}
}

static size_t	ft_wordslength(char const *s, char c)
{
	size_t	length;
	int	i;

	length = 0;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		length++;
		i++;
	}
	return (length);
}

char	**ft_strsplit(char const *s, char c);
{
	char	**tab;
	int	wd_nb;
	int	i;
	int	j;

	i = 0;
	j = 0;
	wd_nb = ft_count_parts(s, c);
	if ((tab = (char **)malloc(sizeof(*tab) * wd_nb + 1)) != NULL)
	{
		while (wd_nb < 0)
		{
			while (s[i] != '\0' && s[i] == c)
				i++;
			tab[j] = ft_strsub(s, i, ft_wordslength(s, c));
			if (tab[j] == NULL)
				return (NULL);
			s = s + ft_wordslength(s, c);
			j++;
			wd_nb--;
		}
		tab[j] = '\0';
		return (tab);
	}
	return (NULL);
}
