#include "filler.h"

void	play_btlr(t_filler *fill)
{
	int i;
	int j;

	i = fill->smap_y - 1;
	while (i >= 1 - fill->spiece_y)
	{
		fill->put_y = i;
		j = 1 - fill->spiece_x;
		while (j < fill->smap_x)
		{
			fill->put_x = j;
			if (check_play(fill))
				return ;
			j++;
		}
		i--;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_btrl(t_filler *fill)
{
	int i;
	int j;

	i = fill->smap_y - 1;
	while (i >= 1 - fill->spiece_y)
	{
		fill->put_y = i;
		j = fill->smap_x - 1;
		while (j >= 1 - fill->spiece_x)
		{
			fill->put_x = j;
			if (check_play(fill))
				return ;
			j--;
		}
		i--;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_tbrl(t_filler *fill)
{
	int i;
	int j;

	i = 1 - fill->spiece_y;
	while (i < fill->smap_y)
	{
		fill->put_y = i;
		j = fill->smap_x - 1;
		while (j >= 1 - fill->spiece_x)
		{
			fill->put_x = j;
			if (check_play(fill))
				return ;
			j--;
		}
		i++;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_tblr(t_filler *fill)
{
	int i;
	int j;

	i = 1 - fill->spiece_y;
	while (i < fill->smap_y)
	{
		fill->put_y = i;
		j = 1 - fill->spiece_x;
		while (j < fill->smap_x)
		{
			fill->put_x = j;
			if (check_play(fill))
				return ;
			j++;
		}
		i++;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}
