/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 12:51:29 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 16:06:47 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "headers/libft.h"
# include "headers/mlx.h"
# include "headers/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>

# define WIDTH 800
# define HEIGHT 600

# define MOVE_UP 13
# define MOVE_UP2 126
# define MOVE_LEFT 0
# define MOVE_LEFT2 123
# define MOVE_RIGHT 2
# define MOVE_RIGHT2 124
# define MOVE_DOWN 1
# define MOVE_DOWN2 125
# define JUMP 49
# define ESC 53

# define PRESS_MASK (1L<<0)
# define PRESS 2

typedef struct			s_int_xy
{
	int					x;
	int					y;
}						t_int_xy;

typedef struct			s_double_xy
{
	double				x;
	double				y;
}						t_double_xy;

typedef struct			s_player
{
	struct s_double_xy	pos;
	struct s_double_xy	dir;
	struct s_double_xy	plane;
	double				turning_speed;
	double				mv_speed;
	int					z;
	char				jumping;
	char				mv_left;
	char				mv_right;
	char				mv_up;
	char				mv_down;
	char				mv_jump;
}						t_player;

typedef struct			s_ray
{
	struct s_double_xy	pos;
	struct s_double_xy	dir;
	struct s_double_xy	side;
	struct s_double_xy	delta;
	struct s_int_xy		map;
	struct s_int_xy		step;
	double				dist;
	double				cam;
	int					hit;
	int					hit_side;
}						t_ray;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
	clock_t				last_frame;
	clock_t				next_frame;
}						t_mlx;

typedef struct			s_env
{
	struct s_mlx		mlx;
	struct s_player		player;
	struct s_ray		ray;
	int					height;
	int					width;
	int					**map;
	int					map_height;
	int					map_width;
	unsigned int		col_north_wall;
	unsigned int		col_south_wall;
	unsigned int		col_east_wall;
	unsigned int		col_west_wall;
	unsigned int		col_sky;
	unsigned int		col_ground;
	int					start_x;
	int					start_y;
}						t_env;

int						loop_hook(t_env *e);

int						open_file(t_env *e, char *f);

int						key_hook(int keycode, t_env *e);
int						key_press(int keycode, t_env *e);

t_env					*init_env(void);

void					draw_line(t_env *e, int x, int start, int end);

void					raycasting(t_env *e);

void					mv_left(t_env *e);
void					mv_right(t_env *e);
void					mv_up(t_env *e);
void					mv_down(t_env *e);
void					mv_jump(t_env *e);

void					error_map(void);
void					error_arg(void);
void					error_malloc(void);

#endif
