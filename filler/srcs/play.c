#include "filler.h"

int		find_me(t_filler *fill, int y, float vs, float me)
{
	int		tab[5];
	char	c;

	tab[0] = y;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	c = (fill->pchar == 'O') ? 'X' : 'O';
	while (tab[1] < fill->smap_x)
	{
		if (fill->map[tab[0]][tab[1]] == c)
			tab[2]++;
		if (fill->map[tab[0]][tab[1]] == (char)(fill->lpchar)
				|| fill->map[tab[0]][tab[1]] == (char)(fill->pchar))
			tab[3]++;
		if (fill->map[tab[0]][tab[1]] != '.')
			tab[4]++;
		tab[1]++;
	}
	if (tab[2] > (int)((float)fill->smap_x * vs)
			|| tab[3] > (int)((float)fill->smap_x * me)
			|| tab[4] >= fill->smap_x - 1)
		return (1);
	return (0);
}

void		play(t_filler *fill)
{
	int		mid_x;
	int		mid_y;

	mid_x = (int)(fill->smap_x / 2);
	mid_y = (int)(fill->smap_y / 2);
	if (O_DEBUG == 1)
		ft_printf("MID MAP %d %d\n", mid_y, mid_x);
	top_play1(fill, mid_x, mid_y);
	top_play2(fill, mid_x, mid_y);
	top_play3(fill, mid_x, mid_y);
	top_play4(fill, mid_x, mid_y);
	top_play5(fill, mid_x, mid_y);
	bottom_play1(fill, mid_x, mid_y);
	bottom_play2(fill, mid_x, mid_y);
	bottom_play3(fill, mid_x, mid_y);
	bottom_play4(fill, mid_x, mid_y);
}
