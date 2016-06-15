#include "rtv1.h"

static void	vect_pt_light(t_env *e, t_p3D *spot, t_p3D *point, t_p3D *ray)
{
	*point = (t_p3D){e->eye.x + e->e * e->vect.x, e->eye.y + e->e * e->vect.y, e->eye.y + e->e * e->vect.z};
	*ray = (t_p3D){spot->x - point->x, spot->y - point->y, spot->z - point->z};
}

int		shadow_cast(t_env *e, t_p3D *spot, int color)
{
	t_p3D	pt;
	t_p3D	ray;
	float	tab_val;
	float	tab[2];
	t_obj	*tmp;

	if (e->current_obj->type_obj != PLAN)
		return (color);
	vect_pt_light(e, spot, &pt, &ray);
	tab_val = -1;
	tmp = e->obj;
	while (tmp)
	{
		if (tmp != e->current_obj)
		{
			calc_current_object(&pt, &ray, tmp, tab);
			if (tab[0] > 0.1 && tab[0] < 0.9)
				tab_val = tab[0];
			if (tab[1] > 0.1 && tab[1] < 0.9)
				tab_val = tab[1];
		}
		tmp = tmp->next;
	}
	color = (tab_val != -1) ? mult_color(color, 0.8) : color;
	return(color);
}
