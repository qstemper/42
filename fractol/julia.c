#include "fractol.h"

int	julia(t_env *e)
{
	t_cplx	z;
	int	i;
	float	tmp;

	i = 0.0;
	tmp = exp(-root(squared(e->x_diff) + squared(e->y_diff)));
	while (i < e->n && (e->x_diff + e->y_diff) < 4.0)
	{
		z.r = e->x_diff;
		z.im = e->y_diff;
		e->x_diff = squared(z.r) - squared(e->y_diff) + e->dx;
		e->y_diff = 2.0 * z.r * z.im + e->dy;
		tmp = exp(-root(squared(e->x_diff) + squared(e->y_diff)));
		i++;
	}
	if (e->theme < 3)
		i = calc_frac(i, tmp, 1.0);
	e->color = fractol_color(i, (e->theme > 2 ? e->theme - 3 : e->theme));
	put_pixel(e);
	return (1);
}

void	launch_julia(t_env *e)
{
	e->y = 0;
	while (e->y < e->img_height)
	{
		e->x = 0;
		while (e->x < e->img_width)
		{
			julia(e);
			e->x = e->x + 1;
		}
		e->y = e->y + 1;
	}
}
