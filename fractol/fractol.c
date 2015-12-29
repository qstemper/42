#include "fractol.h"

int		key(int keycode, void *p)
{
	t_env	*e;

	e = (t_env *)p;
	if (keycode == 53 | keycode == 12)
	{
		mlx_destroy_window(e->mlx, e->win);
		mlx_destroy_image(e->mlx, e->img);
	}
	exit(0);
}

int		fractol_mlx()
{
	t_env	e;
	float	x;
	float	y;

	x = 0.0;
	y = 0.0;
	if (!(e.mlx = mlx_init()))
		return (0);
	if (!(e.img = mlx_image_create(e.mlx, img_x, img_y)))
		return (0);
	mandelbrot(e, x, y);
	if (!(e.win = mlx_new_window(e.mlx, img_x, img_y, "Mandelbrot")) = 0)
		return (0);
	mlx_image_put_to_window(e.mlx, e.win, e.img, img_x, img_y);
	mlx_key_hook(e.win, key, (void *)&e);
	mlx_loop(e.mlx);
	return (1);
}

int		main(int ac, char **av)
{
	int	ret;

	if (ac < 2)
	{
		ft_putendl("Fractales disponibles :");
		ft_putendl("Ensemble de Julia");
		ft_putendl("Ensemble de Mandelbrot");
		return (0);
	}
	if ((ret = fractol_mlx()) == 0)
		return (-1);
	return (0);
}
