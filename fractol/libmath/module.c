#include "libmath.h"

float	cplxmod(t_cplx z)
{
	if (z.r == 0.0 && z.im == 0.0)
		return (0.0);
	else if (z.im == 0.0)
		return (absolute(z.r));
	else if (z.r == 0.0)
		return (-1.0);
	else if (z.r == 1 && z.im == 1)
		return (root(2.0));
	else if (z.r == 1 / 2 && z.im == root(3) / 2)
		return (1.0);
	else
		return (root(squared(z.r) + squared(z.im)));
}
