#include "fractol.h"

int	launch_frac(t_env *e)
{
	if (e->frac_type == 1)
		launch_mand(e);
	else if (e->frac_type == 2)
		launch_julia(e);
	else if (e->frac_type == 3)
		launch_dragon(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (1);
}

int		key(int keycode, void *p)
{
	t_env	*e;
	float	tmp;

	e = (t_env *)p;
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(e->mlx, e->win);
		mlx_destroy_image(e->mlx, e->img);
		exit(0);
	}
	if (keycode == 17)
		e->theme += (e->theme == 5 ? -5 : 1);
	else if (keycode == 125 || keycode == 126)
	{
		tmp = (e->y_max - e->y_min) / 4;
		e->y_max += (keycode == 125 ? tmp : -tmp);
		e->y_min += (keycode == 125 ? tmp : -tmp);
	}
	else if (keycode == 123 || keycode == 124)
	{
		tmp = (e->x_max - e->x_min) / 4;
		e->x_max += (keycode == 124 ? tmp : -tmp);
		e->x_min += (keycode == 124 ? tmp : -tmp);
	}
	else if ((e->n > 1 && keycode == 0) || keycode == 2)
		e->n += (keycode == 2 ? 1 : -1);
	launch_frac(e);
	return (keycode);
}

int	mouse(int button, int x, int y, t_env *e)
{
	float	x_diff;
	float	y_diff;

	x_diff = dx(e, x);
	y_diff = dx(e, y);
	if (button == 1 || button == 4)
	{
		e->x_min = x_diff + ((e->x_min - x_diff) / 2);
		e->x_max = e->x_max + ((x_diff - e->x_max) / 2);
		e->y_min = y_diff + ((e->y_min - y_diff) / 2);
		e->y_max = e->y_max + ((y_diff - e->y_max) / 2);
	}
	else if (button == 2 || button == 5)
	{
		e->x_min = e->x_min - ((e->x_max - e->x_min) / 2);
		e->x_max = e->x_max + ((e->x_max - e->x_min) / 2);
		e->y_min = e->y_min - ((e->y_max - e->y_min) / 2);
		e->y_max = e->y_max - ((e->y_max - e->y_min) / 2);
	}
	launch_frac(e);
	return (0);
}

int	mouse_bis(int x, int y, t_env *e)
{
	e->xs = dx(e, x);
	e->ys = dy(e, y);
	if (e->frac_type == 3)
		e->xs = x;
	launch_frac(e);
	return (0);

}

int		main(int ac, char **av)
{
	t_env	e;
	int	ret;

	if ((ret = init_env(&e, ac, av)) == 0)
			return (-1);
	mlx_key_hook(e.win, key, &e);
	mlx_mouse_hook(e.win, mouse, &e);
	mlx_hook(e.win, 6, 64, mouse_bis, &e);
	mlx_expose_hook(e.win, launch_frac, &e);
	mlx_loop(e.mlx);
	return (0);
}
