#include "rtv1.h"

void		initialization(t_env *e)
{
	t_p3D	pos_cyl;
	t_p3D	pos_sphere;
	t_p3D	pos_cone;
	t_p3D	pos_plan;
	t_p3D	rot;
	t_p3D	rot_plan;

	pos_cyl = (t_p3D){0, 120, 140};
	pos_sphere = (t_p3D){0, -90, 0};
	pos_cone = (t_p3D){0, 0, 0};
	pos_plan = (t_p3D){0, 0, -90};
	rot = (t_p3D){0, 0, 0};
	rot_plan = (t_p3D){0, -0.1, 0};
	e->focale = -(WIDTH / tan(0.2)) - 200;
	e->eye = (t_p3D){e->focale, 0, 0};
	e->rot_eye = (t_p3D){0, 0, 0};
	e->spot = (t_p3D){0, 200, 400};
	e->spot2 = (t_p3D){0, -200, 400};
	e->obj = NULL;
	add_object(&(e->obj), new_object(CYLINDER, pos_cyl, rot, 0xFF55FF));
	add_object(&(e->obj), new_object(SPHERE, pos_sphere, rot, 0x55FF55));
	add_object(&(e->obj), new_object(CONE, pos_cone, rot, 0xFFFF55));
	add_object(&(e->obj), new_object(PLAN, pos_plan, rot_plan, 0xFF));
}
