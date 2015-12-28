#include "fractol.h"

void	mandelbrot(float x, float y)
{
	t_cplx	c;
	t_cplx	z;
	float	tmp;
	int	i;

	while (x < img_x)
	{
		while (y < img_y)
		{
			c.r = x_min + (x / zoom);
			c.im = y_min + (y / zoom);
			z.r = 0.0;
			z.im = 0.0;
			i = 0;
			tmp = z.r;
			z.r = square(z.r) - square(z.i) + c.r;
			z.i = 2 * z.i * tmp + c.i;
			i += 1;
			while (module(z) < 2 && i <= ite_max)
				i++
			if (i == ite_max)
				//Pixel noir du point (x, y)
			else
				//Pixel couleur i*255/ite_max de (x, y) | ici couleur en bleu
			x++;
		}
		y++;
	}
}
