#include "fractol.h"

int	launch_frac(t_env *e)
{
	if (e->frac_type == 1)
		mandelbrot(e);
	else if (e->frac_type == 2)
		julia(e);
	else if (e->frac_type == 3)
		launch_dragon(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 10, WHITE, "Iterations :");
	mlx_string_put(e->mlx, e->win, 150, 10, WHITE, ft_itoa(e->n));
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
		tmp = (e->y1 - e->y2) / 4;
		e->y1 += (keycode == 125 ? tmp : -tmp);
		e->y2 += (keycode == 125 ? tmp : -tmp);
	}
	else if (keycode == 123 || keycode == 124)
	{
		tmp = (e->x1 - e->x2) / 4;
		e->x1 += (keycode == 124 ? tmp : -tmp);
		e->x2 += (keycode == 124 ? tmp : -tmp);
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

	e->x_diff = (((e->x1 - e->x2) * x) / e->img_height) + e->x2;
	e->y_diff = (((e->y1 - e->y2) * y) / e->img_height) + e->y2;
	if (button == 1 || button == 4)
	{
		e->x2 = x_diff + ((e->x2 - x_diff) / 2);
		e->x1 = e->x1 + ((x_diff - e->x1) / 2);
		e->y2 = y_diff + ((e->y2 - y_diff) / 2);
		e->y1 = e->y1 + ((y_diff - e->y1) / 2);
	}
	else if (button == 2 || button == 5)
	{
		e->x2 = e->x2 - ((e->x1 - e->x2) / 2);
		e->x1 = e->x1 + ((e->x1 - e->x2) / 2);
		e->y2 = e->y2 - ((e->y1 - e->y2) / 2);
		e->y1 = e->y1 - ((e->y1 - e->y2) / 2);
	}
	launch_frac(e);
	return (0);
}

int	mouse_bis(int x, int y, t_env *e)
{
	e->dx = (((e->x1 - e->x2) * x) / e->img_height) + e->x2;
	e->dy = (((e->y1 - e->y2) * y) / e->img_height) + e->y2;
	if (e->frac_type == 3)
		e->dx = x;
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
