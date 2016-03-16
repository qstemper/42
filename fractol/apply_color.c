#include "frac.h"

void		color_apply(t_env *e, t_frac *fractal, int (*f)(t_env *e, t_frac, t_point*))
{
	t_point	pt;
	int	col_pix;

	pt.y = 0;
	while (pt.y < e->height)
	{
		pt.x = 0;
		while (pt.x < e->width)
		{
			col_pix = (*f)(e, *fractal, &pt);
			pixel_draw_img(&(pt), e, col_pix);
			pt.x = pt.x + 1;
		}
		pt.y = pt.y + 1;
	}
}
