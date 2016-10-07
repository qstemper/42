/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 11:16:55 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/07 11:20:39 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFF_H
# define BUFF_H

# include "header.h"

typedef struct	s_buff
{
	int			ret;
	int			fd;
	size_t		buff_size;
	char		*buff;
}				t_buff;

t_buff			*new_buff(int fd, size_t buff_size);
void			exp_buff(t_buff **buff, size_t buff_size);
void			del_buff(t_buff **buff);

#endif
