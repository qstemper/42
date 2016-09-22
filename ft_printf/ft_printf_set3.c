#include "ft_printf.h"

void		set_color(int *color, const char *format)
{
	int		n;

	n = 0;
	while (*(format + ++n))
	{
		if (*(format + n) == '}')
				break ;
	}
	if (!*(format + n))
			return ;
	*color |= color_flag(++format);
}

int			set_precision(t_printf_mode *mode, const char *format, va_list ap)
{
	int		n;

	if (*++format == '*')
	{
		mode->precision = va_arg(ap, int);
		return (2);
	}
	mode->precision = ft_atoi(format);
	n = 1;
	while (ft_isdigit(*format++))
			n++;
	return (n);
}

int			set_width(t_printf_mode *mode, const char *format)
{
	int		n;

	n = 0;
	mode->width = ft_atoi(format);
	while (ft_isdigit(*format++))
			n++;
	return (n);
}

int			set_aster(t_printf_mode *mode, const char *format, va_list ap)
{
	int 	width;

	width = va_arg(ap, int);
	if (width < 0)
	{
		mode->flag |= LADJUST;
		mode->width = -width;
	}
	else
			mode->width = width;
	return (1);
	if (format)
			return (1);
}
