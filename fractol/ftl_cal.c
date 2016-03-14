#include "frac.h"

void		ftl_cal_apply(t_env *e, t_frac *ftl, int (*f)(t_env *e, t_frac, t_point*))
{
	t_point	pt;
	int	col_pix;

	pt.y = 0;
	while (pt.y < e->win_size_h)
	{
		pt.x = 0;
		while (pt.x < e->win_size_w)
		{
			col_pix = (*f)(e, *ftl, &pt);
			ftl_draw_pixel_img(&(pt), e, col_pix);
			pt.x = pt.x + 1;
		}
		pt.y = pt.y + 1;
	}
}
