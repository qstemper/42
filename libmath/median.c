#include "libmath.h"

float	median(float x, float y, float z)
{
	if ((x > y && x < z) || (x < y && x > z))
		return (x);
	else if ((y > x && y < z) || (y < x && y > z))
		return (y);
	else if ((z > x && z < y) || (z < x && z > y))
		return (z);
}
