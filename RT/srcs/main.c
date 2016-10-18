/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 08:05:18 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 09:49:07 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					update_img(t_env *e)
{
	int				i;
	int				j;
	t_thread_input	*in;

	i = -1;
	while (++i < RES_SPLIT)
	{
		j = -1;
		while (++j < RES_SPLIT)
		{
			if (!(in = (t_threqd_input *)malloc(sizeof(input))))
			{
				ft_printf("{red{%s{eoc}\n", MSG_THREAD);
				return (1);
			}
			in->x1 = j * (e->e_scene->scene->width / RES_SPLIT);
			in->y1 = i * (e->e_scene->scene->height / RES_SPLIT);
			in->x1 = e->e_scene->scene->width - (RES_SPLIT - 1 - j) * \
					 (e->e_scene->scene->width / RES_SPLIT);
			in->x2 = 
		}
	}
}

static int			loop(t_env *e)
{
	if (is_key(e->key))
		key_check(e->key);
	if (!e->run_thread)
	{
		update_res_cam(e->e_scene->scene->res_cam, e->e_scene->scene->cam);
		if (e->frame->img_refresh < e->frame->scene_refresh)
			img_res(e);
		if (e->frame->light_refresh < e->frame->scene_refresh)
			update_img
	}
	usleep(4000);
	return (0);
}

static int			expose_hook(t_env *e)
{
	e->frqme->scene_refresh = clock();
	return (0);
}

static void			error_mlx(int res)
{
	if (res == 1)
		ft_printf("{red}%s{eoc}\n", MSG_MEM);
	else if (res == 2)
		ft_printf("{red}%s{eoc}\n", MSG_MLX);
	else if (res == 3)
		ft_printf("{red}%s{eoc}\n", MSG_WIN);
	else if (res == 4)
		ft_printf("{red}%s{eoc}\n", MSG_IMG);
	else if (res == 5)
		ft_printf("{red}%s{eoc}\n", MSG_DATA);
	else
		return (0);
	exit(0);
}

int					main(int ac, char **av)
{
	t_env			*e;
	int				res;

	if ((res = env_init(e)) == 0)
		return (0);
	if (ac > 1 && ft_strequ(av[1], "-edit"))
		e->frame->fast_mode = 1;
	else
		e->frame->block = 1;
	if (e->frame->fast_mode == 1 && ac == (2 + e->frame->fast_mode))
		parse_file(av[1 + e->frame->fast_mode]);
	create_inter_thread(e);
	res = mlx_init(e);
	error_mlx(res);
	mlx_expose_hook(e->mlx.win, expose_hook, NULL);
	mlx_hook(e->mlx.win, KPRESS, KPMASK, key_press, e->key);
	mlx_hook(e->mlx.win, KREL, KRMASK, key_release, e->key);
	mlx_hook(e->mlx.win, BPRESS, BPMASK, mouse_press, NULL);
	mlx_hook(e->mlx.win, BREL, BRMASK, mouse_release, NULL);
	mlx_hook(e->mlx.win, MNOTIFY, MNMASK, motion_notify, NULL);
	mlx_loop_hook(e->mlx.mlx, loop, NULL);
	mlx_loop(e->mlx.mlx);
	return (0);
}
