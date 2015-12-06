#include "libmath.h"

float	min3(float x, float y, float z)
{
	if (x <= y && x <= z)
		return (x);
	if (y <= x && y <= z)
		return (y);
	return (z);
}
