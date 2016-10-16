/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 13:56:31 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 14:06:01 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		key_rel_arrow(int keycode, t_env *e)
{
	if (keycode == R_ARROW)
		e->event.key.right = 0;
	else if (keycode == L_ARROW)
		e->event.key.left = 0;
	else if (keycode == U_ARROW)
		e->event.key.up = 0;
	else if (keycode == D_ARROW)
		e->event.key.down = 0;
	return (keycode);
}

static int		key_rel_wasd(int keycode, t_env *e)
{
	if (keycode == W)
		e->event.key.w = 0;
	else if (keycode == A)
		e->event.key.a = 0;
	else if (keycode == S)
		e->event.key.s = 0;
	else if (keycode == D)
		e->event.key.d = 0;
	return (keycode);
}

static int		key_rel_num(int keycod, t_env *e)
{
	if (keycode == NUM_PLUS)
		e->event.key.num_plus = 0;
	else if (keycode == NUM_MINUS)
		e->event.key.num_minus = 0;
	return (keycode);
}

int				key_release(int keycode, t_env *e)
{
	if (keycode > 122 && keycode < 127)
		key_rel_arrow(keycode, e);
	else if (keycode == PAGE_UP)
		e->event.key.page_up = 0;
	else if (keycode == PAGE_DOWN)
		e->event.key.page_down = 0;
	else if (keycode == NUM_PLUS || keycode == NUM_MINUS)
		key_rel_num(keycode, e);
	else if (keycode > -1 && keycode < 14)
		key_rel_wasd(keycode, e);
	else if (keycode == DEL)
		e->event.key.del = 0;
	else if (keycode == CTRL_L || keycode == CTRL_R)
		e->event.key.ctrl = 0;
	else if (keycode == TAB)
		e->event.key.tab = 0;
	else if (keycode == ALT_L || keycode == ALT_R)
		e->event.key.alt = 0;
	else if (keycode == SPACE)
		e->event.key.space = 0;
	return (keycode);
}
