/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:39:43 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/17 15:23:49 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(int keycode, void *p)
{
	t_env	*e;

	e = (t_env *)p;
	clear(p);
	if (keycode == 69)
		e->zoom *= 2;
	else if (keycode == 78)
		e->zoom /= 2;
	draw(p);
}

void		destroy_window(void *p)
{
	t_env	*e;

	e = (t_env *)p;
	mlx_destroy_window(e->mlx, e->win);
	ft_lstdel(&(e->list), NULL);
	exit(0);
}
