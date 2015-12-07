#include "libmath.h"

float			arctan(float x)
{
	int		k;
	float		y;

	k = 0;
	y = 0;
	while (k < 4096)
	{
		y = y + (power(-1.0, k) * ((power(x, 2 * k + 1)) / (2.0 * k + 1.0)));
		k++;
	}
	return (y);
}
