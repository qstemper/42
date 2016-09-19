#ifndef WCHAR_H
# define WCHAR_H

# include "header.h"

# define MASK1 49280
# define MASK2 14712960
# define MASK3 4034953344

size_t	ft_wclen(wchar_t *s);
void	ft_wctoa(wchar_t *ws, char *s);

#endif
