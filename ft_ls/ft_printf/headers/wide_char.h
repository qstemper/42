#ifndef WIDECHAR_H
# define WIDECHAR_H

# include "header.h"

# define MASK1 49280
# define MASK2 14712960
# define MASK3 4034953344

size_t	w_c_len(wchar_t *s);
void	wide_ctoa(wchar_t *wide_s, char *s);

#endif
