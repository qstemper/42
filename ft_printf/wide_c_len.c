#include "ft_printf.h"

size_t		wide_c_len(wchar_t *s)
{
	size_t	i;

	i = 0;
	while (s[i] != L'\0')
			i++;
	return (i);
}
