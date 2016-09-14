#include "wolf3d.h"

int			key_press(t_env *e, int keycode)
{
	if (keycode == DIR_ARROW_LEFT)
			e->player.mv.left = 1;
	if (keycode == DIR_ARROW_UP)
			e->player.mv.up = 1;
	if (keycode == DIR_ARROW_RIGHT)
			e->player.mv.right = 1;
	if (keycode == DIR_ARROW_DOWN)
			e->player.mv.down= 1;
	if (keycode == SPRINT)
			e->player.sprint = 1;
	return (0);
}

int			key_release(t_env e, int ikeycode)
{
	if (keycode == ESC)
			exit(0);
	if (keycode == DIR_ARROW_LEFT)
			e->player.mv.left = 0;
	if (keycode == DIR_ARROW_UP)
			e->player.mv.up = 0;
	if (keycode == DIR_ARROW_RIGHT)
			e->player.mv.right = 0;
	if (keycode == DIR_ARROW_DOWN)
			e->player.mv.down= 0;
	if (keycode == SPRINT)
			e->player.sprint = 0;
	return (0);
}

static void	turn(t_env *e, char dir)
{
	double	tmpdir;
	double	tmpplane;
	int		coef;

	coef  = 1;
	tmpdir = e->player.dir.x;
	tmpplane = e->ray.plane.x;
	if (dir == 'R')
			coef = -1;
	e->player.dir.x = e->player.dir.x * cos(coef * e->player.rspeed) - e->player.dir.y * sin(coef * e->player.rspeed);
	e->player.dir.y = tmpdir * sin(coef * e->player.rspeed) + e->player.dir.y * cos(coef * e->player.rspeed);
	e->ray.plane.x = e->ray.plane.x * cos(coef * e->player.rspeed) - e->ray.plane.y * sin(coef * e->player.rspeed);
	e->ray.plane.x = tmpplane * sin(coef * e->player.rspeed) + e->ray.plane.y * cos(coef * e->player.rspeed);
}

void		move(t_env *e)
{
	if (e->player.mv.up)
	{
		if (!(e->map.map[(int)(e->player.pos.x + e->player.dir.x * e->player.mspeed)][(int)(e->player.pos.y)]))
				e->player.pos.x += e->player.dir.x * e->playermspeed;
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y + e->player.dir.y * e->player.mspeed)]))
				e->player.pos.y += e->player.dir.y * e->playermspeed;
	}
	if (e->player.mv.left)
			turn(e, 'L');
	if (e->player.mv.right)
			turn(e, 'R');
	if (e->player.mv.down)
	{
		if (!(e->map.map[(int)(e->player.pos.x - e->player.dir.x * e->player.mspeed)][(int)(e->player.pos.y)]))
				e->player.pos.x -= e->player.dir.x * e->playermspeed;
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y - e->player.dir.y * e->player.mspeed)]))
				e->player.pos.y -= e->player.dir.y * e->playermspeed;
	}
	if (e->player.sprint)
			e->player.mspeed *= 0.05;
}
