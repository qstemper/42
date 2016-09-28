/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:44:03 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/28 17:47:25 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H

# define FRAC_H

# include "headers/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define HEIGHT 729
# define WIDTH 729
# define ITE_MAX 50

# define ESC 53
# define QUIT 0
# define RELOAD 15

# define LEFT_CLIC 1
# define RIGHT_CLIC 2
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define MOUSE_LEFT 7
# define MOUSE_RIGHT 6

# define BOARD_1 18
# define BOARD_2 19
# define BOARD_3 20
# define BOARD_4 21

# define PAD_DOT 65
# define PAD_ENTER 76
# define PAD_0 82
# define PAD_1 83
# define PAD_2 84
# define PAD_3 85
# define PAD_4 86
# define PAD_5 87
# define PAD_MINUS 78
# define PAD_PLUS 69

# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

# define MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define PRESS_MASK (1L<<0)
# define PRESS 2

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct	s_cplx
{
	float		r;
	float		im;
}				t_cplx;

typedef struct	s_palette
{
	int			col_def;
	int			col_0;
	int			col_1;
	int			col_2;
	int			col_3;
	int			col_4;
	int			col_5;
	int			col_6;
	int			col_7;
	int			col_8;
	int			col_9;
}				t_pal;

typedef struct	s_frac
{
	t_cplx		c;
	t_cplx		z;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		zoom_x;
	float		zoom_y;
	float		zoom_ratio;
	float		tmp;
	int			ite;
	int			ite_max;
	void		*func;
}				t_frac;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixel_img;
	int			bpp;
	int			sizeline;
	int			endian;
	int			height;
	int			width;
	int			stop_motion;
	char		**av;
	t_frac		*ptr;
	t_frac		*array;
	t_pal		*col_ptr;
	t_pal		*col_array;
}				t_env;

void			param_error(int n);

void			open_window(char *title, t_env *e);
void			pixel_draw_img(t_point *point, t_env *e, int col);
void			draw_img(t_env *e);

int				mouse(int button, int x, int y, t_env *e);
int				motion(int x, int y, t_env *e);
int				key(int keycode, t_env *e);

void			color_apply(t_env *e, t_frac *fractal, \
		int (*f)(t_env *e, t_frac, t_point*));

void			init_frac(t_env *e);
int				mandelbrot(t_env *e, t_frac fractal, t_point *point);
int				julia(t_env *e, t_frac fractal, t_point *point);
int				mandelbar(t_env *e, t_frac fractal, t_point *point);
int				b_ship(t_env *e, t_frac fractal, t_point *point);
int				menger(t_env *e, t_frac fractal, t_point *point);

int				rgb_creating(int r, int g, int b);
void			frac_change(char *name, t_env *e);
void			key_frac_change(int keycode, t_env *e);
void			key_color_change(int keycode, t_env *e);

void			init_color(t_env *e);
void			change_color(int num, t_env *e);
int				get_color(int z, t_pal pal);

#endif
