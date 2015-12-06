#include "libmath.h"

float	root(float x)
{
	float	res;
	int	n;

	if (x < 0.0)
		return (-1.0);
	if (x == 0.0 || x == 1.0)
		return (x);
	res = x / 2.0;
	n = 4096;
	while(square(res) - x != 0.0001 && n-- > 0)
		res = (res + (x / res)) / 2.0;
	return (res);
}
