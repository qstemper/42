#include "frac.h"

void	error_malloc(void)
{
	ft_putstr_fd("Malloc Error\n", 2);
	exit(1);
}

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
}

void	print_error_ex(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
