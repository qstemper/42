#ifndef LIBMATH_H

# define LIBMATH_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define PI 3.14159265

float	max(float x, float y);
float	max3(float x, float y, float z);
float	min(float x, float y);
float	min3(float x, float y, float z);
float	square(float x);
float	median(float x, float y, float z);
float	power(float x, int pow);
float	absolute(float x);
float	root(float x);
float	res_0_deg(float x);
float	res_1_deg(float x, float y);
float	res_2_deg(float x, float y, float z);
float	nb_digit(float x);
float	arctan(float x);
float	tangente(float x);






#endif
