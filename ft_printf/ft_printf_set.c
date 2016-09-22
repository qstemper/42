#include "ft_printf.h"

int				set_format_mode(const char *format, t_printf_mode *mode, t_printf_set_function *set_mode, va_list ap)
{
	const char	*cp;
	int			index;

	cp = ++format;
	while (*format)
	{
		index = get_mode_index(MODE_CSET, *format);
		if (index == -1)
				break ;
		format += set_mode[index](mode, format, ap);
	}
	mode->special = *format;
	return (format - (cp - 1));
}
