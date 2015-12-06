#include "libmath.h"

float	res_1_deg(float x, float y)
{
	if (x != 0 && y != 0)
		return (-x/y);
	return (res_0_deg(y));
}
