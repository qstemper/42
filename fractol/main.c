#include "frac.h"

static int	expose_hook(t_env *e)
{
	draw_img(e);
	return (0);
}

static void	usage_error(void)
{
	print_error("Unexpected parameter used !\n");
	print_error("Choose one of the following :\n");
	print_error_ex("Mandelbrot, Julia, Carpet, B_Ship, Mandelbar\n");
}

static void	check_params(int ac, char **av)
{
	if (ac != 2)
		usage_error();
	if (ft_strcmp(av[1], "Mandelbrot") != 0 &&\
			ft_strcmp(av[1], "Julia") != 0 &&\
			ft_strcmp(av[1], "Mandelbar") != 0 &&\
			ft_strcmp(av[1], "B_Ship") != 0 &&\
			ft_strcmp(av[1], "Carpet") != 0)
		usage_error();
}

int		main(int ac, char **av)
{
	t_env	*e;

	check_params(ac, av);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		error_malloc();
	e->win_size_h = WINDOW_SIZE_H;
	e->win_size_w = WINDOW_SIZE_W;
	e->stop_motion = 1;
	open_window("42 Fractol", e);
	init_frac(e);
	init_color(e);
	frac_change(av[1], e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, mouse, e);
	mlx_hook(e->win, KEY_PRESS, KEY_PRESS_MASK, key, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, motion, e);
	mlx_loop(e->mlx);
	return (0);
}
