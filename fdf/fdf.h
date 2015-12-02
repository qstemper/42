/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:46:56 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/02 17:13:56 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft.h"
# include "get_next_Line.h"
# include "lexer.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_point3D
{
	int				x;
	int				y;
	int				z;

}					t_point3D;

fdf(int fd);

#endif
