/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:24:08 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 20:45:01 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			search_obj(int search)
{
	t_obj			*obj;

	obj = env->e_scene.scene.obj;
	while (obj)
	{
		if ((int)obj == search)
		{
			remove_obj(env->e_scene.scene, obj);
			return (1);
		}
		obj = obj->next;
	}
	return (0);
}

static int			search_light(int search)
{
	t_light			*light;

	light = env->e_scene.scene.light;
	while(light)
	{
		if ((int)light == search)
		{
			remove_light(env->e_scene.scene, light);
			return (1);
		}
		light = light->next;
	}
	return (0);
}

void				cmd_remove(char **line)
{
	int				search;

	if (!line || !*line)
	{
		ft_printf("{red}%s{eoc}\n", MSG_LINE);
		ft_printf("{grey}%s{eoc}", USE_REM);
		return ;
	}
	search = (unsigned int)ft_atoi(*line);
	if (search_obj(search))
		return ;
	if (search_light(light))
		return ;
	ft_printf("%s\n", OBJ_LOST);
}
