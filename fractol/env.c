#include "fractol.h"

void	print_error(int c)
{
	if (c == 1)
		ft_putendl("Too few or too much parameters entered !");
	else	
	{
		ft_putendl("Wrong parameter !");
		ft_putendl("Please use one of the following :");
		ft_putendl("\tMandelbrot for the Mandelbrot Set");
		ft_putendl("\tJulia for the Julia Set");
		ft_putendl("\tDragon for the Dragon Curve");
	}
}

int	frac_test(int ac, char **av)
{
	if (ac != 2)
		print_error(1);
	else if (ft_strcmp(av[1], "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(av[1], "Julia") == 0)
		return (2);
	else if (ft_strcmp(av[1], "Dragon") == 0)
		return (3);
	print_error(2);
	return (0);
}

void	frac_bound(t_env *e)
{
	if (e->frac_type == 1)
	{
		e->x1 = 1;
		e->x2 = -2.5;
		e->y1 = 2;
		e->y2 = -1;
	}
	else if (e->frac_type == 2)
	{
		e->x1 = 2;
		e->x2 = -2;
		e->y1 = 2;
		e->y2 = -2;
	}
	else if (e->frac_type == 3)
	{
		e->x1 = 4;
		e->x2 = -4;
		e->y1 = 4;
		e->y2 = -4;
		e->dx = e->img_width / 2;
	}
}

int		init_env(t_env *e, int ac, char **av)
{
	t_vector3D	vect;

	e->frac_type = frac_test(ac, av);
	e->img_height = HEIGHT;
	e->img_width = WIDTH;
	if (!(e->mlx = mlx_init()))
		return (0);
	if (!(e->win = mlx_new_window(e->mlx, e->img_height, e->img_width, av[1])))
		return (0);
	if (!(e->img = mlx_new_image(e->mlx, e->img_height, e->img_width)))
		return (0);
	if (!(e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian))))
		return (0);
	e->dx = 0;
	e->dy = 0;
	e->n = 50;
	e->theme = 0;
	vect = (t_vector3D){0.0, 0.0, 0.0};
	e->color = vect;
	frac_bound(e);
	e->x_orir = e->x1;
	e->x_oril = e->x2;
	return (1);
}
