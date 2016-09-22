/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:46:56 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/23 00:09:55 by qstemper         ###   ########.fr       */
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
# include <math.h>


# define GAP_X (1024.0 / 1.5) / (1.0 + (float)e->x_max)
# define GAP_Y (1024.0 / 1.5) / (1.0 + (float)e->y_max)
# define COLOR_GAP 0xFF0
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define POS_COLOR(Z) ((RED + GREEN) - ((GREEN / BLUE) * Z))
# define NEG_COLOR(Z) ((BLUE + GREEN) - ((GREEN / BLUE) * Z))
# define UNKNOWN_COLOR(Z) (Z > 0.0 ? POS_COLOR((int)Z) : NEG_COLOR((int)-Z))

typedef struct		s_p3d
{
	float			x;
	float			y;
	float			z;
}					t_p3d;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_list			*list;
	int				x_max;
	int				y_max;
	int				**mat;
	int				dx;
	int				dy;
	float			zoom;
}					t_env;

typedef struct		s_matrix
{
	int				**grid;
}					t_matrix;

int					fdf(char *str, t_list **listpoint, int *x, int *y);
int					fdf_getcolor(int c);
int					fdf_mlx(t_list **list, char *str, int x, int y);
int					draw(void *p);
int					clear(void *p);
void				zoom(int keycode, void *p);
void				reinit(void *p);
void				modif_plus_z(void *p);
void				modif_minus_z(void *p);
void				destroy_window(void *p);

float				fdf_view_iso_x(t_env *e, int i, int j);
float				fdf_view_iso_y(t_env *e, int i, int j);

int					**matrix_crea(t_env e);
int					**matrix_init(t_env e);
int					**matrix_fill(t_env e);

int					bres_color(int c1, int c2);
void				bresenham(t_env *e, int c);
void				bres_sup_oct1(t_env *e, t_p3d p1, t_p3d p2, int color);
void				bres_sup_oct2(t_env *e, t_p3d p1, t_p3d p2, int color);
void				bres_sup_oct3(t_env *e, t_p3d p1, t_p3d p2, int color);
void				bres_sup_oct4(t_env *e, t_p3d p1, t_p3d p2, int color);
void				bres_inf_oct1(t_env *e, t_p3d p1, t_p3d p2, int color);
void				bres_inf_oct2(t_env *e, t_p3d p1, t_p3d p2, int color);
void				bres_inf_oct3(t_env *e, t_p3d p1, t_p3d p2, int color);
void				bres_inf_oct4(t_env *e, t_p3d p1, t_p3d p2, int color);
void				bres_dx_null(t_env *e, t_p3d p1, t_p3d p2, int color);

#endif
