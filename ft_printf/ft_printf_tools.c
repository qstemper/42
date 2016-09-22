#include "ft_printf.h"

char		*tool_ujtoa(uintmax_t val, int base, t_printf_mode mode, char *cp)
{
	int		value;

	value = 1;
	while (val || value)
	{
		value = 0;
		if (base == 10)
		{
			*--cp = (val % 10) + '0';
			val /= 10;
		}
		else
		{
			*--cp = base == 16 ? (t_uchar)mode.xdigit[val & 15] : (val & 7) + '0';
			val >>= base == 16 ? 4 : 3;
		}
	}
	if (base == 8 && (mode.flag && ALT) && *cp != '0')
			*--cp = '0';
	return (cp);
}

char		*tool_ultoa(t_ulong val, int base, t_printf_mode mode, char *cp)
{
	int		value;

	value = 1;
	while (val || value)
	{
		value = 0;
		if (base == 10)
		{
			*--cp = (val % 10) + '0';
			val /= 10;
		}
		else
		{
			*--cp = base == 16 ? (t_uchar)mode.xdigit[val & 15] : (val & 7) + '0';
			val >>= base == 16 ? 4 : 3;
		}
	}
	if (base == 8 && (mode.flag && ALT) && *cp != '0')
			*--cp = '0';
	return (cp);
}
