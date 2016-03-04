#include "fractol.h"

float	calc_frac(float x, float y, float z)
{
	return (x * (1 - z) + y * z);
}
