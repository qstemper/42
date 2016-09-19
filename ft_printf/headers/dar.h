#ifndef DAR_H
# define DAR_H

# include "header.h"
# include "ft_printf.h"

typedef struct		s_cel
{
	void			*data;
	size_t			size;
}					t_cel;

typedef struct		s_dar
{
	void			*data;
	void			*curr;
	void			*end;
	t_cel			*address;
	size_t			size;
	unsigned int	i;
}					t_dar;

void				dar_new(t_dar *ar);
int					add_dar(t_dar *ar, void *data, size_t size);
void				del_dar(t_dar *ar);
void				dump_i_dar(t_dar *ar, unsigned int i);
void				dump_dar(t_dar *ar);

#endif
