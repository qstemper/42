#include "wolf3d"

static void	init_ray(t_env *e, int x)
{
	e->player.high_cam = 2 * x / (double)(WIDTH) - 1;
	e->ray.pos.x = e>player.pos.x;
	e->ray.pos.y = e>player.pos.y;
	e->ray.dir.x = e->player.dir.x + e->ray.plane.x * e->player.high_cam;
	e->ray.dir.y = e->player.dir.y + e->ray.plane.y * e->player.high_cam;
	e->ray.posmap.xi = (int)e->ray.pos.x;
	e->ray.posmap.yi = (int)e->ray.pos.y;
	e->ray.d_dis.x = sqrt(1 + (e->ray.dir.y * e->ray.dir.y) / (e->ray.dir.x * e->ray.dir.x));
	e->ray.d_dis.y = sqrt(1 + (e->ray.dir.x * e->ray.dir.x) / (e->ray.dir.y * e->ray.dir.y));
	e->player.hit = 0;
}

static void	ray_dir(t_env *e)
{
	if (e->ray.dir.x < 0)
	{
		e->player.step.xi = -1;
		e->ray.dist_side.x = (e->ray.posmap.xi + 1.0 - e->ray.pos.x) * e->ray.d_dis.x;
	}
	else
	{
		e->player.step.xi = 1;
		e->ray.dist_side.x = (e->ray.posmap.xi + 1.0 - e->ray.pos.x) * e->ray.d_dis.x;

	}
	if (e->ray.dir.y < 0)
	{
		e->player.step.yi = -1;
		e->ray.dist_side.y = (e->ray.posmap.yi + 1.0 - e->ray.pos.y) * e->ray.d_dis.y;
	}
	else
	{
		e->player.step.yi = 1;
		e->ray.dist_side.y = (e->ray.posmap.yi + 1.0 - e->ray.pos.y) * e->ray.d_dis.y;

	}
}

static void	dda(t_env *e)
{
	while (e->player.hit == 0)
	{
		if (e->ray.dist_side.x < e->ray/dist_side.y)
		{
			e->ray.dist_side.x += e->ray.d_dis.x;
			e->ray.posmap.xi += e->player.step.xi;
			e->player.wallside = 0;
		}
		else
		{
			e->ray.dist_side.y += e->ray.d_dis.y;
			e->ray.posmap.yi += e->player.step.yi;
			e->player.wallside = 1;
		}
		if (e->map.map[e->ray.posmap.xi][e->ray.posmap.yi] > 0)
				e->player.hit = 1;
	}
}

static void	calc(t_env *e)
{
	double distwall;

	if (e->player.wallside == 0)
			distwall = fabs((e->ray.posmap.xi - e->ray.pos.x + (1 - e->player.step.xi) / 2) / e->ray.dir.x);
	else
			distwall = fabs((e->ray.posmap.yi - e->ray.pos.y + (1 - e->player.step.yi) / 2) / e->ray.dir.y);
	e->ray.lheight = abs((int)(HEIGHT) / distwall),
	e->ray.ystart = (-1 * (e->ray.lheight)) / 2 + HEIGHT / 2;
	if (e->ray.ystart < 0)
			e->ray.ystart = 0;
	e->ray.yend = e->ray.lheight / 2 + HEIGHT / 2;
	if (e->ray.yend >= HEIGHT)
			e->ray.yend = HEIGHT -1;
}

int			loop_hook(t_env *e)
{
	t_rgb	color;
	int		x;

	if (e->img != NULL)
	{
		mlx_destroy_image(e->mlx, e->img);
		e->img = NULL;
	}
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	x = 0;
	while (x < WIDTH)
	{
		init_ray(e, x);
		ray_dir(e);
		dda(e);
		calc(e, &color);
		draw(e, &color, x);
		x++;
	}
	get_timframe(e);
	move(e);
	mlx_put_image_to_window(->mlx, e->win, e->img, 0, 0);
	return (0);
}
