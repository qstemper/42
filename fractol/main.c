#include "frac.h"

static int	ftl_expose_hook(t_env *e)
{
	ftl_draw_reload(e);
	return (0);
}

static void	ftl_error_usage(void)
{
	ft_error_str_exit("usage : fractol [Mandelbrot, Julia, Carpet, b_ship, Mandelbar]\n");
}

static void	ftl_check_params(int ac, char **av)
{
	if (ac != 2)
		ftl_error_usage();
	if (ft_strcmp(av[1], "Mandelbrot") != 0 &&\
			ft_strcmp(av[1], "Julia") != 0 &&\
			ft_strcmp(av[1], "Mandelbar") != 0 &&\
			ft_strcmp(av[1], "b_ship") != 0 &&\
			ft_strcmp(av[1], "Carpet") != 0)
		ftl_error_usage();
}

int		main(int ac, char **av)
{
	t_env	*e;

	ftl_check_params(ac, av);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		ft_malloc_error();
	e->win_size_h = WINDOW_SIZE_H;
	e->win_size_w = WINDOW_SIZE_W;
	e->stop_motion = 1;
	ftl_draw_win("42 Fractol", e);
	ftl_frac_init(e);
	ftl_col_init(e);
	ftl_change_frac(av[1], e);
	mlx_expose_hook(e->win, ftl_expose_hook, e);
	mlx_mouse_hook(e->win, ftl_mouse_hook, e);
	mlx_hook(e->win, KEY_PRESS, KEY_PRESS_MASK, ftl_key_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, ftl_motion_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
