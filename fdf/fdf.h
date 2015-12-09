/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:46:56 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/09 14:00:00 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "lexer.h"
# include "libmath.h"
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define GAP_X (1024 / (1.5 * e->x_max))
# define GAP_Y (1024 / (1.5 * e->y_max))
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
	float			zoom;
}					t_env;

typedef struct		s_matrix
{
	int				**grid;
}					t_matrix;

int					fdf(char *str, t_list **listpoint, int *x, int *y);
int					fdf_mlx(t_list **list, char *str, int x, int y);
int					**matrix_crea(t_env e);
int					**matrix_init(t_env e);
int					**matrix_fill(t_env e);
float				fdf_view_iso_x(t_env *e, int i, int j);
float				fdf_view_iso_y(t_env *e, int i, int j);

#endif
