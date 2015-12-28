#include "fractol.h"
#include <unistd.h>
#include <stdio.h>

int	fractol_mlx()
{
	t_env	e;

	if (!(e.mlx = mlx_init()))
		return (0);
	if (!(e.img = mlx_image_create(e.mlx, img_x, img_y)))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2/* || !av*/ /* A changer quand fract implem*/)
	{
		ft_putendl("Fractales disponibles :");
		ft_putendl("Ensemble de Julia");
		ft_putendl("Ensemble de Mandelbrot");
		return (0);
	}
	return (0);
}
