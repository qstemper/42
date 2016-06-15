#include "rtv1.h"

static float	vect_norm(t_p3D *point)
{
	float	res;

	res = sqrt(pow(point->z, 2) + pow(point->y, 2) + pow(point->x, 2));
	return (res);
}

static void	get_n(t_p3D *n, t_p3D *point, t_obj *obj)
{
	if (obj->type_obj == SPHERE)
		*n = (t_p3D){point->x, point->y, point->z};
	else if (obj->type_obj == CYLINDER)
		*n = (t_p3D){point->x, point->y, 0};
	else if (obj->type_obj == CONE)
		*n = (t_p3D){point->x, point->y, -0.1 * point->z};
	else if (obj->type_obj == PLAN)
		*n = (t_p3D){0, 0, 100};
}

int		light_ray(t_env *e, t_p3D *spot)
{
	t_p3D	point;
	t_p3D	ray;
	t_p3D	n;
	float	cos_a;
	int	color;

	point = (t_p3D){e->eye.x + e->e * e->vect.x, e->eye.y + e->e * e->vect.y, e->eye.z + + e->e * e->vect.z};
	ray = (t_p3D){spot->x - point.x, spot->y - point.y, spot->z - point.z};
	color = e->current_obj->color;
	get_n(&n, &point, e->current_obj);
	cos_a = (n.x * ray.x + n.y * ray.y + n.z * ray.z) / (vect_norm(&n) * vect_norm(&ray));
	if (cos_a >= 0 && cos_a <= 1)
		color = mult_color(e->current_obj->color, cos_a);
	else
		color = 0;
	return (color);
}
