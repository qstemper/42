#include "ft_printf.h"

t_list						**buff_list(void)
{
	static t_list			*buff;

	return (&buff);
}

t_printf_color				*color_attribute(int i)
{
	static t_printf_color	color[NB_COLOR_ATTRIBUTE];
	static int				call;

	if (!call)
	{
		init_color(color);
		call = 1;
	}
	return (color + i);
}
