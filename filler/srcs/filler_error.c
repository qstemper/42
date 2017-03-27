#include "filler.h"

void	filler_error(int n)
{
	if (n == 0)
		ft_fprintf(2, "Error Malloc\n");
	if (n == 1 && errno != 0)
	{
		ft_printf("%s\n", strerror(errno));
		perror(PRGM);
	}
	if (n < 2)
		exit(0);
}
