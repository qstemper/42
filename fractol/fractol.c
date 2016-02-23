#include "fractol.h"

int		key(int keycode, void *p)
{
	t_env	*e;

	e = (t_env *)p;
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (keycode);
}

int		fractol_mlx(char **av)
{
	t_env	e;

	e.x = 0.0;
	e.y = 0.0;
	e.pix_nb = 0;
	if (!(e.mlx = mlx_init()))
		return (0);
	if (!(e.img = mlx_new_image(e.mlx, img_x, img_y)))
		return (0);
	if (!(e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sizeline), &(e.endian))))
		return (0);
/*	printf("[%d][%d][%d]\n", e.bpp, e.sizeline, e.endian);
	while (e.pix_nb < 585000)
	{
		e.data[e.pix_nb] = 150;
		e.pix_nb = e.pix_nb + 1;
	}
	if (!(e.win = mlx_new_window(e.mlx, img_x, img_y, av[1])))
		return (0);
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		mlx_expose_hook(e.win, mandelbrot, (void *)&e);
	if (ft_strcmp(av[1], "Julia") == 0)
		mlx_expose_hook(e.win, julia, (void *)&e);*/
	if (ft_strcmp(av[1], "Dragon") == 0)
		mlx_expose_hook(e.win, launch_dragon, (void *)&e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_key_hook(e.win, key, (void *)&e);
	mlx_loop(e.mlx);
	return (1);
}

int		main(int ac, char **av)
{
	int	ret;

	if (ac != 2 || (ac == 2 && ft_strcmp(av[1], "Mandelbrot") != 0 &&\
			ft_strcmp(av[1], "Julia") != 0 && ft_strcmp(av[1], "Dragon") != 0))
	{
		ft_putendl("Wrong parameter !");
		ft_putendl("Please use one of the following :");
		ft_putendl("\tMandelbrot for the Mandelbrot Set");
		ft_putendl("\tJulia for the Julia Set");
		ft_putendl("\tDragon for the Dragon Curve");
		return (0);
	}
	if (ft_strcmp(av[1], "Mandelbrot") == 0 && (ret = fractol_mlx(av)) == 0)
		return (-1);
	else if (ft_strcmp(av[1], "Julia") == 0 && (ret = fractol_mlx(av)) == 0)
		return (-1);
	else if (ft_strcmp(av[1], "Dragon") == 0 && (ret = fractol_mlx(av)) == 0)
		return (-1);
	return (0);
}
