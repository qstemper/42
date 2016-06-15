#include "rtv1.h"

static void	param_error(int n)
{
	if (n == 1)
		ft_putendl("The memory you are trying to allocate has failed !");
	else
		ft_putendl("The parameter used isn't correct");
	exit(1);
}

static void	check_param(int ac)
{
	if (ac != 1)
		param_error(2);
}

int	main(int ac, char **av)
{
	t_env	*e;

	check_param(ac);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		param_error(1);
	e->height = HEIGHT;
	e->width = WIDTH;
	open_window("RTv1", e);
	create_img(e);
	e->bpp = e->bpp >> 3;
	initialization(e);
	calc_rtv1(e);
	mlx_expose_hook(e->win, &expose, e);
	mlx_key_hook(e->win, &key, e);
	mlx_loop(e->mlx);
	return (0);
}
