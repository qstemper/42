#include "libmath.h"

float	power(float x, int pow)
{
	if (pow == 0)
		return (1.0);
	else if (pow == 1)
		return (x);
	else if (pow >= 2 && pow > 0)
		return (x * power(x, pow - 1));
	return (1 / (power(x, -pow)));
}
