#include "ft_printf.h"

int			ft_vfprintf(int fd, const char *format, va_list ap)
{
	int		length;

	length = ft_vlprintf(format, ap);
	if (length != -1)
			flush_fd(fd);
	return (length);
}

int			ft_vsprintf(char *str, const char *format, va_list ap)
{
	int		length;

	length = ft_vlprintf(format, ap);
	if (length != -1)
			flush_str(str);
	return (length);
}

int			ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	int		length;

	length = ft_vlprintf(format, ap);
	if (length != -1)
			flush_nstr(str, size);
	if (length > 0 && length > (int)size)
			return ((int)size);
	else
			return (length);
}

