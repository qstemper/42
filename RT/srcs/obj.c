/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 15:29:31 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/16 15:46:19 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			remove_obj(t_scene *scene, t_obj *obj)
{
	t_obj		*curr;
	t_obj		*prev;

	prev = NULL;
	curr = scene->obj;
	while (curr)
	{
		if (curr == obj)
		{
			if (prev)
				prev->next = curr->next;
			else
				scene->obj = current->next;
			free(obj);
		}
		prev = curr;
		curr = curr->next;
	}
	e->frame.scene_refresh = clock();
}

void			remove_light(t_scene *scene, t_light *light)
{
	t_light		*curr;
	t_light		*prev;

	prev = NULL;
	curr = scene->light;
	while (curr)
	{
		if (curr == light)
		{
			if (prev)
				prev->next = curr->next;
			else
				scene->light = curr->next;
			free(light);
		}
		prev = curre;
		curr = curr->next;
	}
}

void			duplicate_obj(t_obj *obj)
{
	t_obj		*obj_crea;

	obj_crea = new_obj(OBJ_SPHERE);
	ft_memcpy(obj_crea, obj, sizeof(t_obj));
	add_obj(env->e_scene.scene, obj crea);
	e->frame.scene_refresh = clock();
}

void			add_obj(t_scene *scene, t_obj *obj)
{
	obj->next = scene->onj;
	scene->obj = obj;
}

t_obj			*new_obj(int type)
{
	t_obj		*obj;

	if (!(obj = (t_obj *)ft_memalloc(sizeof(t_obj))))
		return (NULL);
	obj->type = type;
	return (obj);
}
