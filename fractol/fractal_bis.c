#include "frac.h"

int		menger(t_env *e, t_frac fractal, t_point *pt)
{
	int	x;
	int	y;

	x = pt->x;
	y = pt->y;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (get_color(0, *(e->col_ptr)));
		y /= 3;
		x /= 3;
	}
	return (get_color(100, *(e->col_ptr)));
}
