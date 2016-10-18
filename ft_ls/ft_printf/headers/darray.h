/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 13:14:45 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 13:14:46 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DARRAY_H
# define DARRAY_H

# include "header.h"

typedef struct		s_cel
{
	void			*data;
	size_t			size;
}					t_cel;

typedef struct		s_darray
{
	void			*data;
	void			*curr;
	void			*end;
	t_cel			*address;
	size_t			size;
	unsigned int	i;
}					t_darray;

void				new_darray(t_darray *array);
int					add_darray(t_darray *array, void *data, size_t size);
void				del_darray(t_darray *array);
void				dump_i_darray(t_darray *array, unsigned int i);
void				dump_darray(t_darray *array);

#endif
