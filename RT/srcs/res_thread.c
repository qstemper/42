/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 07:36:32 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 07:43:43 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		display_ray(t_light_color color, int i, int j, t_env *e)
{
	color.red /= e->e_scene->scene->if_name * e->e_scene->scene->if_name;
	color.green /= e->e_scene->scene->if_name * e->e_scene->scene->if_name;
	color.blue /= e->e_scene->scene->if_name * e->e_scene->scene->if_name;
	res_light(i, j, color);
}

static void		ray_pixel(int x, int y, t_env *e)
{
	float		i;
	float		j;
	t_ray		ray;
	t_light_color	dot;

	ft_bzero(&dot, sizeof(dot));
	i = -1;
	while (+i < e->e_scene->scene->if_name)
	{
		j = -1;
		while (++j < e->e_scene->scene->if_name)
		{
			ray = get_ray_from_point(((float)x + \
			(i / e->e_scene->scene->if_name)), \
			((float)y + (i / e->e_scene->scene->if_name)));
			trace_ray(&ray, 1, 0, e->e_scene->scene->recurs);
			dot.red += ray.color.red;
			dot.green += ray.color.green;
			dot.blue += ray.color.blue;
		}
	}
	display_ray(dot, x, y, e);
}

static void		fast_ray(int x, int y, t_env *e)
{
	t_ray		ray;

	if (x % RES_PREC || y % RES_PREC)
		return ;
	ray = get_ray_from_point((float)x, (float)y);
	trace_ray(&ray, 1, 0, 0);
	fast_res_light(x, y, &ray.color);
}

static void		*trace_view_plane(void *thread_input, t_env *e)
{
	t_thread_input	*input;
	int		i;
	int		j;

	input = (t_thread_input *)thread_input;
	e->frame->light_refresh = clock();
	i = input->y1;
	while(i <= input->y2)
	{
		j = input->x1;
		while (j <=input->x2)
		{
			if (env->frame->fast_mode)
				fast_ray(i, j, e);
			else
				ray_pixel(i, j, e);
			i++;
		}
		j++;
	}
	e->e_scene->run_thread--;
	free(thread_input);
	return(NULL);
}

int			res_thread(t_thread_input *in, t_env *e)
{
	e->e_scene->run_thread++;
	if (pthread_create(e->res_thread[in->nb_thread], NULL, \
		trace_view_plane((void *)in)))
	{
		ft_printf("{red}%s{eoc}\n", MSG_THREAD);
		return (1);
	}
	returb (0);
}
