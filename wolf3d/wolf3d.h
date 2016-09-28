#ifndef WOLF3D_H

# define WOLF3D_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "headers/mlx.h"
# include "headers/libft.h"
# include "headers/get_next_line.h"

# define HEIGHT 720
# define WIDTH 1280

# define DIR_ARROW_LEFT 65361
# define DIR_ARROW_UP 65362
# define DIR_ARROW_RIGHT 65363
# define DIR_ARROW_DOWN 65364

# define SPRINT 65506

# define ESC 65307

typedef struct	s_coord
{
	double		x;
	double		y;
	int			xi;
	int			yi;
}				t_coord;

typedef struct	s_color
{
	int			blue;
	int			red;
	int			green;
}				t_color;

typedef struct	s_moving
{
	int			up;
	int			down;
	int			left;
	int			right;
}				t_moving;

typedef struct	s_ray
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	t_coord		dist_side;
	t_coord		d_dis;
	t_coord		posmap;
	int			lheight;
	int			ystart;
	int			yend;
}				t_ray;

typedef struct	s_player
{
	t_coord		pos;
	t_coord		dir;
	t_coord		step;
	t_moving	mv;
	double		rspeed;
	double		mspeed;
	double		high_cam;
	int			hit;
	int			wallside;
	int			sprint;
}				t_player;

typedef struct	s_map
{
	int			**map;
	int			display;
	int			sizex;
	int			sizey;
}				t_map;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pxl;
	int			bpp;
	int			sizeline;
	int			endian;
	t_player	player;
	t_map		map;
	t_ray		ray;
	double		time;
	double		prevtime;
	long int	frametime;
}				t_env;

void			get_timeframe(t_env *e);
void			move(t_env *e);
void			color(t_env *e, t_color *color);
void			draw(t_env *e, t_color *color, int x);
int				expose_hook(t_env *e);
int				loop_hook(t_env *e);
int				key_release(t_env *e, int keycode);
int				key_press(t_env *e, int keycode);

#endif
