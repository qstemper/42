#include "frac.h"

int		ftl_frac_carpet(t_env *e, t_frac ftl, t_point *pt)
{
	int	x;
	int	y;

	(void)ftl;
	x = pt->x;
	y = pt->y;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (ftl_get_col(0, *(e->p_col_ptr)));
		y /= 3;
		x /= 3;
	}
	return (ftl_get_col(100, *(e->p_col_ptr)));
}
