#include "rtv1.h"

static void	rotation_axis_x(t_p3D *point, t_p3D *rot, int invert)
{
	t_p3D	p;

	p.y = point->y * cos(invert * rot->x) - point->z * sin(invert * rot->x);
	p.z = point->y * sin(invert * rot->x) + point->z * cos(invert * rot->x);
	point->y = p.y;
	point->z = p.z;
}

static void	rotation_axis_y(t_p3D *point, t_p3D *rot, int invert)
{
	t_p3D	p;

	p.x = point->x * cos(invert * rot->y) + point->z * sin(invert * rot->y);
	p.z = point->z * cos(invert * rot->y) - point->x * sin(invert * rot->y);
	point->x = p.x;
	point->z = p.z;
}

static void	rotation_axis_z(t_p3D *point, t_p3D *rot, int invert)
{
	t_p3D	p;

	p.x = point->x * cos(invert * rot->z) - point->y * sin(invert * rot->z);
	p.z = point->x * sin(invert * rot->z) + point->y * cos(invert * rot->z);
	point->x = p.x;
	point->z = p.z;
}

void		rotate_img(t_p3D *point, t_p3D *rot, int invert)
{
	if (invert == -1)
	{
		rotation_axis_x(point, rot, invert);
		rotation_axis_y(point, rot, invert);
		rotation_axis_z(point, rot, invert);
	}
	else
	{
		rotation_axis_z(point, rot, invert);
		rotation_axis_y(point, rot, invert);
		rotation_axis_x(point, rot, invert);
	}
}
