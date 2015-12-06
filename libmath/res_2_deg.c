#include "libmath.h"

void	res_2_deg(float x, float y, float z)
{
	float	delta;
	float	res1;
	float	res2;

	if (a == 0)
		(res_1_deg(y, z));
	delta = square(y) - (4 * x * z);
	if (delta < 0)
		write(1, "Imaginary solutions\n", 20);
	else if (delta == 0)
		res1 = (-y / (2 * x));
	else
	{
		res1 = (-y - root(delta)) / (2 * x);
		res2 = (-y + root(delta)) / (2 * x);
	}
}
