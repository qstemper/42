#include "rtv1.h"

static void	change_view(t_p3D *eye, t_p3D *vect, t_obj *obj, int inv)
{
	if (inv == 1)
	{
		rotate_img(eye, &(obj->rot), inv);
		rotate_img(vect, &(obj->rot), inv);
	}
	eye->x += inv * obj->pos.x;
	eye->y += inv * obj->pos.y;
	eye->z += inv * obj->pos.z;
	vect->x += inv * obj->pos.x;
	vect->y += inv * obj->pos.y;
	vect->z += inv * obj->pos.z;
	if (inv == -1)
	{
		rotate_img(eye, &(obj->rot), inv);
		rotate_img(vect, &(obj->rot), inv);
	}
}

void		calc_current_object(t_p3D *eye, t_p3D *vect, t_obj *obj, float *tab)
{
	change_view(eye, vect, obj, -1);
	if (obj->type_obj == SPHERE)
		sphere(eye, vect, tab);
	else if (obj->type_obj == CYLINDER)
		cylinder(eye, vect, tab);
	else if (obj->type_obj == CONE)
		cone(eye, vect, tab);
	else if (obj->type_obj == PLAN)
		plan(eye, vect, tab);
	change_view(eye, vect, obj, 1);
}

static void	calc_inter(int x, int y, t_env *e)
{
	float	k[2];
	t_obj	*tmp;
	int	color;

	e->e = 0xFFFFFF;
	e->current_obj = NULL;
	tmp = e->obj;
	while (tmp)
	{
		calc_current_object(&(e->eye), &(e->vect), tmp, k);
		if (k[0] >= 0 && e->e > k[0] && (e->current_obj = tmp))
			e->e = k[0];
		if (k[1] >= 0 && e->e > k[1] && (e->current_obj = tmp))
			e->e = k[1];
		tmp = tmp->next;
	}
	if (e->current_obj != NULL)
	{
		color = light_ray(e, &(e->spot));
		color = add_color(color, light_ray(e, &(e->spot2)));
		color = mult_color(color, 0.7);
		color = shadow_cast(e, &(e->spot), color);
		color = shadow_cast(e, &(e->spot2), color);
		img_draw(e, x, y, color);
	}
}

static void	calc_ray_xy(int x, int y, t_env *e)
{
	e->plan.x = e->focale;
	e->plan.y = WIDTH / 2.0 - x;
	e->plan.z = HEIGHT / 2.0 - y;
	e->vect.x = e->plan.x - e->eye.x;
	e->vect.y = e->plan.y - e->eye.y;
	e->vect.z = e->plan.z - e->eye.z;
	rotate_img(&(e->vect), &(e->rot_eye), 1);
	calc_inter(x, y, e);
}

void		calc_rtv1(t_env *e)
{
	int	x;
	int	y;
	int	prev_view;

	prev_view = -1;
	rotate_img(&(e->eye), &(e->rot_eye), 1);
	x = -1;
	while(++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			calc_ray_xy(x, y, e);
			if (100 * (x * HEIGHT + y) / (HEIGHT * WIDTH) > prev_view + 1)
				prev_view = 100 * (x * HEIGHT + y) / (HEIGHT * WIDTH);
		}
	}
}
