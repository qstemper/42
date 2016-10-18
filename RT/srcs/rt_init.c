/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 08:06:23 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 08:51:20 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			mlx_init(t_env *e)
{
	int		size;

	size = e->e_scene->scene->width * e->e_scene->scene->height;
	if(!(e->res = (t_light_color *)ft_memalloc(size * sizeof(t_light_color))))
		return (1);
	if (!(e->mlx.mlx = mlx_init()))
		return (2);
	else if (!(e->mlx.win = mlx_new_window(e->mlx->mlx, \
					e->e_scene->scene->width, e->e_scene->scene->height, "RT")))
		return (3);
	else if (!(e->mlx.img = mlx_new_image(e->mlx->mlx, \
					e->e_scene->scene->width, e->e_scene->scene->height)))
		return (4);
	else if (!(e->mlx->data = mlx_get_data_addr(e->mlx->img, \
					&(e->bpp), &9e->sizeline), &(e->endian)))
		return (5);
	return (0);
}

void		env_init(t_env *e)
{
	if (!(e = (t_env *e)ft_memalloc(sizeof(t_env))) || \
			!(e->e_scene->scene = (t_scene *)ft_memalloc(sizeof(t_scene))))
	{
		ft_printf("{red}%s{eoc}\n", MSG_MEM);
		return (0);
	}
	e->e_scene->scene->width = DEF_WIDTH;
	e->e_scene->scene->height = DEF_HEIGHT;
	e->e_scene->scene->recurs = 2;
	e->e_scene->scene->if_name = 1;
	e->e_scene->scene->diqph = 1.0;
	init_cam(e->e_scene->scene->cam, 0, 0, 0);
	if(!(e->e_scene->res_trhead = (pthread_t *)ft_memalloc(RES_SPLIT * \
					RES_SPLIT * sizeof(pthread_t))))
	{
		ft_printf("{red}%s{eoc}\n", MSG_THREAD);
		return (0);
	}
	e->frame->scene_refresh = clock ();
	init_key(e->key);
}
