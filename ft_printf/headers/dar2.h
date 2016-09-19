#ifndef DAR2_H
# define DAR2_H

# include "haeder.h"

# define DAR2_OFFSET 32

typedef void	(*t_dar_del)(void *);

typedef struct	s_dar2
{
	void		**ar;
	size_t		size_content;
	size_t		size;
	size_t		size_max;
	t_dar_del	del;
}				t_dar2;

int				new_dar2(t_dar2 *dar, size_t size, t_dar_del del);
int				add_dar2(t_dar2 *dar, void *data);
void			dump_dar2(t_dar2 *dar, void (*f)(void *));
void			del_dar2(t_dar2 *dar);

#endif
