#include <stdio.h>
#include "libft/includes/libft.h"
#include "ft_printf/ft_printf.h"

int		main()
{
	int	i = 0;

	while (i++ < 10)
			ft_printf("[{red|underline|font-yellow}%20s{eoc}]{blue|font-green}%15d{eoc}\n", "Salut!", 42);
	return (0);
}
