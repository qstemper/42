#ifndef DARRAY2_H
# define DARRAY2_H

# include "header.h"

# define DARRAY2_OFFSET 32

typedef void	(*t_darray_del)(void *);

typedef struct	s_darray2
{
	void			**array;
	size_t			size_content;
	size_t			size;
	size_t			size_max;
	t_darray_del	del;
}					t_darray2;

int				new_darray2(t_darray2 *darray, size_t size, t_darray_del del);
int				add_darray2(t_darray2 *darray, void *data);
void			dump_darray2(t_darray2 *darray, void (*f)(void *));
int				del_darray2(t_darray2 *darray);

#endif
