#include "rtv1.h"

t_obj	*new_object(t_type_obj type_obj, t_p3D pos, t_p3D rot, int color)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->type_obj = type_obj;
	obj->pos = pos;
	obj->rot = rot;
	obj->color = color;
	obj->next = NULL;
	return (obj);
}

void	add_object(t_obj **obj, t_obj *new_obj)
{
	t_obj	*tmp;

	if(!(*obj))
		*obj = new_obj;
	else
	{
		tmp = *obj;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new_obj;
	}
}
