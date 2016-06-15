#include "rtv1.h"

int	key(int keycode, t_env *e)
{
	if (keycode == ESC || keycode == QUIT)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	return (0);
}

int	expose(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		return (0);
}
