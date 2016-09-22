#include "ft_printf.h"

int			get_mode_index(char *cset, char c)
{
	char	*f;

	f = ft_strchr(cset, c);
	if (f)
			return (f - cset);
	else if (ft_isdigit(c))
			return (NB_MODE_FUNCTION - 1);
	else
			return (-1);
}

int			get_special_index(char *cset, char c)
{
	char	*f;

	f = ft_strchr(cset, c);
	if (f)
			return (f - cset);
	else
			return (NB_SPECIAL_FUNCTION - 1);
}
