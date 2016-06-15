#include "rtv1.h"

void		sphere(t_p3D *eye, t_p3D *vect, float *k)
{
	float	a;
	float	b;
	float	c;
	float	delta;

	a = pow(vect->x, 2) + pow(vect->y, 2) + pow(vect->z, 2);
	b = 2 * (eye->x * vect->x + eye->y * vect->y + eye->z * vect->z);
	c = pow(eye->x, 2) + pow(eye->y, 2) + pow(eye->z, 2) - pow(R, 2);;
	delta = pow(b, 2) - 4 * a * c;
	if (delta >= 0)
	{
		k[0] = (-b - sqrt(delta)) / (2 * a);
		k[1] = (-b + sqrt(delta)) / (2 * a);
	}
	else
	{
		k[0] = -1;
		k[1] = -1;
	}
}

void		cylinder(t_p3D *eye, t_p3D *vect, float *k)
{
	float	a;
	float	b;
	float	c;
	float	delta;

	a = pow(vect->x, 2) + pow(vect->y ,2);
	b = 2 * (eye->x * vect->x + eye->y * vect->y);
	c = pow(eye->x, 2) + pow(eye->y, 2) - pow(R / 1.5, 2);
	delta = pow(b, 2) - 4 * a * c;
	if (delta >= 0)
	{
		k[0] = (-b - sqrt(delta)) / (2 * a);
		k[1] = (-b + sqrt(delta)) / (2 * a);
	}
	else
	{
		k[0] = -1;
		k[1] = -1;
	}
}

void		cone(t_p3D *eye, t_p3D *vect, float *k)
{
	float	a;
	float	b;
	float	c;
	float	width;
	float	delta;

	width = 0.7 * vect->z;
	a = pow(vect->x, 2) + pow(vect->y, 2) - pow(width, 2);
	b = 2 * (eye->x * vect->x + eye->y * vect->y - eye->z * width);
	c = pow(eye->x, 2) + pow(eye->y, 2) - pow(eye->z, 2);
	delta = pow(b, 2) - 4 * a * c;
	if (delta >= 0)
	{
		k[0] = (-b - sqrt(delta)) / (2 * a);
		k[1] = (-b + sqrt(delta)) / (2 * a);
	}
	else
	{
		k[0] = -1;
		k[1] = -1;
	}
}

void		plan(t_p3D *eye, t_p3D *vect, float *k)
{
	if (vect->z > -0.000001 && vect->z < 0.000001)
		k[0] = 1;
	else
		k[0] = -eye->z / vect->z;
	k[1] = -1;
}
