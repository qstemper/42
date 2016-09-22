#include "libft.h"

static int	size_word(char *s, char c)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		res++;
	}
	return (res);
}

static void	cons_tab_int(int nb_w, char c, int *tab, char *s)
{
	int		i;
	int		j;
	int		size;

	while (s[i] != '\0' && j < nb_w)
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') ||\
				(s[0] != c && i == 0))
		{
			if (s[i] == c)
					i++;
			size = size_word(&s[i], c);
			tab[j] = ft_atoi(ft_strsub(s, i, size));
			j++;
		}
		i++;
	}
}

int			*ft_strsplittoint(char const *s, char c)
{
	int		*tab;
	int		nb_w;
	int		i;

	if (s == NULL)
			return (NULL);
	i = 0;
	nb_w = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') ||\
				(s[0] != c && i == 0))
			nb_w++;
		i++;
	}
	if (!(tab = (int *)malloc(sizeof(int) * nb_w)))
			return (NULL);
	cons_tab_int(nb_w, c, tab, (char *)s);
	return (tab);	
}
