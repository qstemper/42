#include "lemin.h"

static void		ft_getopt_bis(char **av, char *cs, int j, int *to)
{
	int		i;
	int		o;
	char		*tmp;

	i = 0;
	while (av[j][++i])
	{
		tmp = cs;
		o = 0x1;
		while (*tmp)
		{
			if (av[j][i] == *tmp)
			{
				to += o;
				break ;
			}
			o <<= 1;
			tmp++;
		}
	}
}

int			ft_getopt(int ac, char **av, char *charset)
{
	int		to;
	int		j;

	to = 0;
	j = 0;
	while (++j < ac)
	{
		if (av[j][0] != '-')
			break ;
		ft_getopt_bis(av, charset, j, &to);
		
	}
	return (to);
}
