#ifndef FRACTOL_H

# define FRACTOL_H

# include "headers/libft.h"
# include "headers/libmath.h"
# include <mlx.h>
# include <unistd.h>
# include <math.h>

# define HEIGHT 640
# define WIDTH 480
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
	int		img_height;
	int		img_width;
	t_vector3D	color;
	float		x;
	float		y;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		x_diff;
	float		y_diff;
	int		n;
	int		dx;
	int		dy;
	int		theme;
	int		frac_type;
	int		x_orir;
	int		x_oril;
}			t_env;

typedef struct		s_point
{
	int		abs;
	int		ord;
}			t_p2d;

int			init_env(t_env *e, int ac, char **av);
int			mandelbrot(t_env *e);
int			julia(t_env *e);
int			launch_dragon(void *p);
int			dragon(t_env *e, int i, t_p2d P, t_p2d Q);
t_vector3D		fractol_color(float x, int theme);
void			put_pixel(t_env *e);
float			calc_frac(float x, float y, float z);

#endif
