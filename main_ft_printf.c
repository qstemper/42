#include <stdio.h>
#include "headers/libft.h"

int		main()
{
	int	i = 0;

	while (i++ < 10)
			ft_printf("[{red|underline|font-yellow}%20s{eoc}]{blue|font-green}%15d{eoc}\n", "Salut!", 42);
	return (0);
}
