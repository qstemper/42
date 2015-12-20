#include "fdf.h"

int		bres_color(int c1, int c2)
{
	int	c;

	if (!c1 || !c2)
		return (BLACK);
	if (c1 != c2)
	{
		if (c1 == WHITE && c2 > GREEN )
			c = c2 + 0x008800;
		else if (c2 == WHITE && c1 > GREEN)
			c = c1 + 0x008800;
		else if (c1 == WHITE && c2 < GREEN )
			c = c2 + 0x008800;
		else if (c2 == WHITE && c1 < GREEN)
			c = c1 + 0x008800;
		else
			c = ((c1 + c2) / 2);
	}
	else
		c = c1;
	return (c);
}
