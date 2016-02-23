#include "fractol.h"

int	julia(void *p)
{
	t_env	*e;
	t_cplx	c;
	t_cplx	z;
	int	i;
	float	tmp;

	e = (t_env *)p;
	while (e->x < img_x)
	{
		while (e->y < img_y)
		{
			c.r = 0.3;
			c.im = 0.5;
			z.r = x_min + e->x / zoom;
			z.im = y_min + e->y / zoom;
			i = 0;
			while (i < 50)
			{
				tmp = z.r;
				z.r = squared(z.r) - squared(z.im) + c.r;
				z.im = 2 * tmp * z.im + c.im;
				if (cplxmod(z) >= 2)
					break;
				i++;
			}
			if (cplxmod(z) >= 2)
				mlx_pixel_put(e->mlx, e->win, e->x, e->y, i * GREEN / 50);
			e->y = e->y + 1;
		}
		e->y = 0;
		e->x = e->x + 1;
	}
	return (1);;

}
