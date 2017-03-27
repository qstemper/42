#include "filler.h"

void	play_tblr_y(t_filler *fill)
{
	int i;
	int j;

	j = 1 - fill->spiece_x;
	while (j < fill->smap_x)
	{
		fill->put_x = j;
		i = 1 - fill->spiece_y;
		while (i < fill->smap_y)
		{
			fill->put_y = i;
			if (check_play(fill))
				return ;
			i++;
		}
		j++;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_tbrl_y(t_filler *fill)
{
	int i;
	int j;

	j = fill->smap_x - 1;
	while (j >= 1 - fill->spiece_x)
	{
		fill->put_x = j;
		i = 1 - fill->spiece_y;
		while (i < fill->smap_y)
		{
			fill->put_y = i;
			if (check_play(fill))
				return ;
			i++;
		}
		j--;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_btrl_y(t_filler *fill)
{
	int i;
	int j;

	j = fill->smap_x - 1;
	while (j >= 1 - fill->spiece_x)
	{
		fill->put_x = j;
		i = fill->smap_y - 1;
		while (i >= 1 - fill->spiece_y)
		{
			fill->put_y = i;
			if (check_play(fill))
				return ;
			i--;
		}
		j--;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}

void	play_btlr_y(t_filler *fill)
{
	int i;
	int j;

	j = 1 - fill->spiece_x;
	while (j < fill->smap_x)
	{
		fill->put_x = j;
		i = fill->smap_y - 1;
		while (i >= 1 - fill->spiece_y)
		{
			fill->put_y = i;
			if (check_play(fill))
				return ;
			i--;
		}
		j++;
	}
	fill->put_y = -1;
	fill->put_x = -1;
}
