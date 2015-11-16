#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
	{
		if (nb >= 10)
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putnbr_fd((n % 10), fd);
		}
		else
			ft_putchar_fd((n + 48), fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
}
