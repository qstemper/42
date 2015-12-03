/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:46:56 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/03 17:42:17 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "lexer.h"
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define GAP 42
# define COLOR_GAP 0xFF0

typedef struct		s_p3D
{
	int				x;
	int				y;
	int				z;

}					t_p3D;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_list			*list;
	int				x_max;
	int				y_max;
	int				**mat;
}					t_env;

int					fdf(char *str, t_list **listpoint, int *x, int *y);
int					fdf_mlx(t_list **list, char *str, int x, int y);

#endif