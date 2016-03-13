#include "fractol.h"

int	print_error(int c)
{
	if (c == 1)
	{
		ft_putendl("Too few or too much parameters entered !");
		return (-1);
	}
	else if (c == 2)
	{
		ft_putendl("The parameter used is incorrect!");
		ft_putendl("Please use one of the following :");
		ft_putendl("\tMandelbrot for the Mandelbrot Set");
		ft_putendl("\tJulia for the Julia Set");
		ft_putendl("\tDragon for the Dragon Curve");
		return (-1);
	}
	return (0);
}

int	frac_test(int ac, char **av)
{
	if (ac != 2)
	{
		print_error(1);
		return (-1);
	}
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(av[1], "Julia") == 0)
		return (2);
	else if (ft_strcmp(av[1], "Dragon") == 0)
		return (3);
	print_error(2);
	return (-1);
}

void	frac_edge(t_env *e)
{
	if (e->frac_type == 1)
	{
		e->x_max = 1;
		e->x_min = -2.5;
		e->y_max = 1;
		e->y_min = -1;
	}
	else if (e->frac_type == 2)
	{
		e->x_max = 2;
		e->x_min = -2;
		e->y_max = 2;
		e->y_min = -2;
	}
	else if (e->frac_type == 3)
	{
		e->x_max = 4;
		e->x_min = -4;
		e->y_max = 4;
		e->y_min = -4;
		e->xs = e->width / 2;
	}
}

int		init_env(t_env *e, int ac, char **av)
{
	t_vector3D	vect;

	if ((e->frac_type = frac_test(ac, av)) == -1)
		return (0);
	frac_edge(e);
	e->height = (e->x_max - e->x_min) * zoom;
	e->width = (e->x_max - e->y_min) * zoom;
	if (!(e->mlx = mlx_init()))
		return (0);
	if (!(e->win = mlx_new_window(e->mlx, e->height, e->width, av[1])))
		return (0);
	if (!(e->img = mlx_new_image(e->mlx, e->height, e->width)))
		return (0);
	if (!(e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian))))
		return (0);
	e->xs = 0;
	e->ys = 0;
	e->n = 50;
	e->theme = 0;
	vect = (t_vector3D){0.0, 0.0, 0.0};
	e->color = vect;
	e->x_orir = e->x_max;
	e->x_oril = e->x_min;
	return (1);
}
