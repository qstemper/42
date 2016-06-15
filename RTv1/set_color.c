#include "rtv1.h"

int		mult_color(int color, float prec)
{
	int	i;
	int	tab_col[3];

	i = -1;
	while (++i < 3)
	{
		tab_col[i] = (color >> ((2 - i) << 3)) & 0xFF;
		tab_col[i] = tab_col[i] * prec;
		if (tab_col[i] > 0xFF)
			tab_col[i] = 0xFF;
		if (tab_col[i] < 0)
			tab_col[i] = 0;
	}
	return ((tab_col[0] << 16) + (tab_col[1] << 8) + tab_col[2]);
}

int		add_color(int color, int color_2)
{
	int	i;
	int	tab_col[3];
	int	tab_col_2[3];

	i = -1;
	while (++i < 3)
	{
		tab_col[i] = (color >> ((2 - i) << 3)) & 0xFF;
		tab_col_2[i] = (color_2 >> ((2 - i) << 3)) & 0xFF;
		tab_col[i] = tab_col[i] + tab_col_2[i];
		if (tab_col[i] > 0xFF)
			tab_col[i] = 0xFF;
		if (tab_col[i] < 0)
			tab_col[i] = 0;
	}
	return ((tab_col[0] << 16) + (tab_col[1] << 8) + tab_col[2]);
}
