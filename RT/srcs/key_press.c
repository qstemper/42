/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 04:35:49 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/14 05:14:14 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		key_quit(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	mlx_destroy_image(e->mlx.mlx, e->mlx.img);
	free(*e);
	free(e);
	exit(0);
}

int				key_press(int keycode, t_env *e)
{
	if (keycode == ESC)
		key_quit(t_env *e);
	
}
