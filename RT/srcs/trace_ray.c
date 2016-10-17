#include "rt.h"

static float	intersec(t_obj *obj, t_ray *ray)
{
	t_ray	*new_ray;
	t_obj	*new_obj;

	new_ray = ray;
	new_obj = obj;
	if (obj->type == OBJ_SPHERE)
		return (sphere_eq(obj, ray));
	else if (obj->type == OBJ_PLANE)
		return (plane_eq(obj, ray));
	else if (obj->type == OBJ_CYL)
	{
		chg_ray(ray, new_ray, obj, new_obj);
		return(cyl_eq(new_obj, new_ray));
	}
	else if (obj->type == OBJ_CONE)
	{
		chg_ray(ray, new_ray, obj, new_obj);
		return(con_eq(new_obj, new_ray));
	}
	return (INFINITY);
}

static void	calc_reflec(t_ray *a, t_ray *b)
{
	t_vect	n;
	t_point	intersec;

	intersec.x = a->orig.x * a->inter_t;
	intersec.y = a->orig.y * a->inter_t;
	intersec.z = a->orig.z * a->inter_t;
	if (a->near->type == OBJ_CYL)
		get_cyl_normal(&n, a->near, &intersec);
	else if (a->near->type == OBJ_CONE)
		get_cone_normal(&n, a->near, &intersec);
	else
		n = a->near->normal;
	b->orig = intersec;
	vect_scale(&a->dir, -1);
	b->dir.x = 2 * (vect_dot(&n, &a->dir)) * n.x - a->dir.x;
	b->dir.y = 2 * (vect_dot(&n, &a->dir)) * n.y - a->dir.y;
	b->dir.z = 2 * (vect_dot(&n, &a->dir)) * n.z - a->dir.z;
	normalize_vect(&b->dir);
}

t_ray		get_ray_from_point(float i, float j)
{
	t_ray	ray;

	ray.orig.x = e->e_scene->scene.res_cam.orig.x;
	ray.orig.y = e->e_scene->scene.res_cam.orig.y;
	ray.orig.z = e->e_scene->scene.res_cam.orig.z;
	ray.dir.x = e->e_scene->scene.res_cam..vx.x;
	ray.dir.y = e->e_scene->scene.res_cam..vy.y;
	ray.dir.z = e->e_scene->scene.res_cam..vz.Z;
	i -= e->e_scene->scene.width / 2;
	j -= e->e_scene->scene.height / 2;
	ray.dir.x -= (e->e_scene->res_cam.vy.x / PLANE_PLOT) * i;
	ray.dir.y -= (e->e_scene->res_cam.vy.y / PLANE_PLOT) * i;
	ray.dir.z -= (e->e_scene->res_cam.vy.z / PLANE_PLOT) * i;
	ray.dir.x -= (e->e_scene->res_cam.vy.x / PLANE_PLOT) * j;
	ray.dir.y -= (e->e_scene->res_cam.vy.y / PLANE_PLOT) * j;
	ray.dir.z -= (e->e_scene->res_cam.vy.z / PLANE_PLOT) * j;
	return (ray);
}

static void	ray_reflec(t_ray *ray, t_ray *reflec, int rec)
{
	if (ray->near->reflec > 0.0 && rec > 0)
	{
		calc_reflec(ray, reflec);
		trace_ray(reflec, 1, ray->near, rec - 1);
		ray->color.red *= (1 - ray->near->reflec);
		ray->color.green *= (1 - ray->near->reflec);
		ray->color.blue *= (1 - ray->near->reflec);
		if (reflec.near)
		{
			ray->color.red += ray->near->reflec * reflec->color.red;
			ray->color.green += ray->near->reflec * \
					reflec->color.green;
			ray->color.blue += ray->near->reflec * \
					reflec->color.blue;
		}
	}
}

void		trace_ray(t_ray *ray, t_env *e, t_obj *ignored, int rec)
{
	float	tmp;
	t_obj	*obj;
	t_ray	reflec;

	obj = e->e_scene->scene->obj;
	ray->inter_t = INFINITY;
	ray->near = NULL;
	ray->color.red = 0.0;
	ray->color.green = 0.0;
	ray->color.blue = 0.0;
	while(obj->next)
	{
		if (!ignored || obj != ignored)
		{
			tmp = intersec(obj, ray);
			ray->near = (tmp < ray->inter_t) ? obj : ray->near;
			ray->inter_t = (tmp < ray->inter_t) ? tmp : ray->near;
		}
	}
	if (e->calc_light && ray->inter_t != INFINITY)
	{
		phong_shade(t_ray *ray);
		ray_reflec(ray, &reflec, rec);
	}
}
