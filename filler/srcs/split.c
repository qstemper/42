#include "filler.h"

void		ft_strsplit_free(char ***split)
{
	int		i;

	i = 0;
	if (split == NULL || *split == NULL)
		return ;
	i = ft_strsplit_len(*split);
	if (i > 0)
	{
		while (i >= 0)
		{
			ft_strdel(&split[0][i]);
			i--;
		}
		free(*split);
		*split = NULL;
	}
}

int			ft_strsplit_len(char **split)
{
	int		size;

	size = 0;
	if (split == NULL)
		return (0);
	else
	{
		while (split[size] != NULL)
			size++;
	}
	return (size);
}
