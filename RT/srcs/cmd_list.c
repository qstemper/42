/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 19:39:06 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 20:09:58 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			cmd_list(void)
{
	t_obj		*obj;
	t_light		*light;

	obj = env->e_scene.scene.obj;
	ft("{cyan}%s{eoc} :", OBJ);
	while(obj)
	{
		if (obj->type == OBJ_SPHERE)
			ft_printf("\n\t{pink}%s{eoc}", SPHERE);
		else if (obj->type == OBJ_PLANE)
			ft_printf("\n\t{pink}%s{eoc}", PLANE);
		ft_printf("\t%u\n", (unsigned int)obj);
		obj = obj->next
	}
	light = env->e_scene.scene.light;
	ft_printf("{cyan}%s{eoc} :", LIGHT);
	while(light)
	{
		ft_printf("\n\t{pink}%s\t%u{eoc}\n", LIGHT, (unsigned int)light);
		light = light->next;
	}
}
