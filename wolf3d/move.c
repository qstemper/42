/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:15:45 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/05 12:21:25 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			mv_up(t_env *e)
{
	if (e->map[(int)(e->player.pos.x + e->player.dir.x * e->player.mv_speed)]\
			[(int)e->player.pos.y] == 0)
		e->player.pos.x += e->player.dir.x * e->player.mv_speed;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y + e->player.dir.y * \
				e->player.mv_speed)] == 0)
		e->player.pos.y += e->player.dir.y * e->player.mv_speed;
}

void			mv_down(t_env *e)
{
	if (e->map[(int)(e->player.pos.x - e->player.dir.x * e->player.mv_speed)]\
			[(int)e->player.pos.y] == 0)
		e->player.pos.x -= e->player.dir.x * e->player.mv_speed;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y - e->player.dir.y * \
				e->player.mv_speed)] == 0)
		e->player.pos.y -= e->player.dir.y * e->player.mv_speed;
}

void			mv_right(t_env *e)
{
	t_double_xy	old;

	old.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(-e->player.turning_speed) - \
					e->player.dir.y * sin(-e->player.turning_speed);
	e->player.dir.y = old.x * sin(-e->player.turning_speed) + \
					e->player.dir.y * cos(-e->player.turning_speed);
	old.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(-e->player.turning_speed) - \
					e->player.plane.y * sin(-e->player.turning_speed);
	e->player.plane.y = old.x * sin(-e->player.turning_speed) + \
					e->player.plane.y * cos(-e->player.turning_speed);
}

void			mv_left(t_env *e)
{
	t_double_xy	old;

	old.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(e->player.turning_speed) - \
					e->player.dir.y * sin(e->player.turning_speed);
	e->player.dir.y = old.x * sin(e->player.turning_speed) + \
					e->player.dir.y * cos(e->player.turning_speed);
	old.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(e->player.turning_speed) - \
					e->player.plane.y * sin(e->player.turning_speed);
	e->player.plane.y = old.x * sin(e->player.turning_speed) + \
					e->player.plane.y * cos(e->player.turning_speed);
}

void			mv_jump(t_env *e)
{
	if (e->player.z >= 100)
		e->player.jumping = 1;
	if (e->player.jumping == 1)
		e->player.z -= 10;
	if (e->player.jumping == 0)
		e->player.z += 10;
	if (e->player.jumping == 1 && e->player.z == 0)
	{
		e->player.jumping = 0;
		e->player.mv_jump = 0;
	}
}
