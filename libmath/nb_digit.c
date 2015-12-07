#inclue "libmath.h"

int	nb_digit(float x)
{
	unsigned int	nb;

	nb = 0;
	while (x != 0)
	{
		x = x % 10;
		nb++;
	}
	return (nb);
}
