#include "filler.h"

static int	check_play_bis(t_filler *fill, int i, int j, int *nb)
{
	int y;
	int x;

	x = fill->put_x;
	y = fill->put_y;
	while (j < fill->spiece_x)
	{
		if (fill->piece[i][j] == '*' && (y + i < 0 || x + j < 0
					|| y + i >= fill->smap_y || x + j >= fill->smap_x))
			return (0);
		else if (fill->piece[i][j] == '*'
				&& fill->map[y + i][x + j] == fill->pchar)
			(*nb)++;
		else if (fill->piece[i][j] == '*'
				&& fill->map[y + i][x + j] == fill->lpchar)
			(*nb)++;
		else if (fill->piece[i][j] == '*' && fill->map[y + i][x + j] != '.')
			return (0);
		if (*nb > 1)
			return (0);
		j++;
	}
	return (1);
}

int			check_play(t_filler *fill)
{
	int i;
	int j;
	int nb;
	int ret;

	nb = 0;
	ret = 0;
	i = 0;
	while (i < fill->spiece_y)
	{
		j = 0;
		if((ret = check_play_bis(fill, i, j, &nb)) == 0)
			return (0);
		i++;
	}
	if (nb != 1)
		return (0);
	return (ret);
}
