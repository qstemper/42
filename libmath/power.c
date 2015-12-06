#include "libmath.h"

float	power(float x, int pow)
{
	if (pow == 0)
		return (1.0);
	if (pow == 1)
		return (x);
	if (pow >= 2)
		return (x * power(x, pow - 1));
	if (pow < 0)
		return (1 / (power(x, -pow)));
}
