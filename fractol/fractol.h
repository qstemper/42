#ifndef FRACTOL_H

# define FRACTOL_H

# include "headers/libft.h"
# include "headers/libmath.h"
# include <mlx.h>
# include <unistd.h>
# include <math.h>

# define zoom 100
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000

typedef struct		s_vector3D
{
	float		x;
	float		y;
	float		z;
}			t_vector3D;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		height;
	int		width;
	t_vector3D	color;
	int		frac_type;
	int		n;
	int		x;
	int		y;
	int		theme;
	float		x_min;
	float		x_max;
	float		y_min;
	float		y_max;
	float		x_orir;
	float		x_oril;
	float		xs;
	float		ys;
	}		t_env;

typedef struct		s_point
{
	int		abs;
	int		ord;
}			t_p2d;

int			init_env(t_env *e, int ac, char **av);
void			launch_mand(t_env *e);
void			launch_julia(t_env *e);
int			launch_dragon(void *p);
t_vector3D		fractol_color(float x, int theme);
void			put_pixel(t_env *e);
float			calc_frac(float x, float y, float z);
float			dx(t_env *e, int x);
float			dy(t_env *e, int y);

#endif
