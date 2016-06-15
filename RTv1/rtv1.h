#ifndef RTV1_H

# define RTV1_H

# include "headers/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define HEIGHT	729
# define WIDTH	729

# define R 100

# define ESC	53
# define QUIT	0

typedef struct		s_p3D
{
	float		x;
	float		y;
	float		z;
}			t_p3D;

typedef enum		e_type_obj
{
			SPHERE,
			CYLINDER,
			CONE,
			PLAN
}			t_type_obj;

typedef struct		s_obj
{
	t_type_obj	type_obj;
	t_p3D		pos;
	t_p3D		rot;
	int		color;
	struct s_obj	*next;
}			t_obj;

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
	int		x;
	int		y;
	char		**av;
	t_obj		*obj;
	t_p3D		eye;
	t_p3D		rot_eye;
	t_p3D		plan;
	t_p3D		vect;
	t_p3D		spot;
	t_p3D		spot2;
	float		focale;
	float		e;
	t_obj		*current_obj;
}			t_env;

void			open_window(char *title, t_env *e);
void			create_img(t_env *e);

void			initialization(t_env *e);

t_obj			*new_object(t_type_obj type_obj, t_p3D pos, t_p3D rot, int color);
void			add_object(t_obj **obj, t_obj *new_obj);

int			key(int keycode, t_env *e);
int			expose(t_env *e);

void			img_draw(t_env*e, int x, int y, int color);
int			light_ray(t_env *e, t_p3D *spot);

void			sphere(t_p3D *eye, t_p3D *vect, float *k);
void			cylinder(t_p3D *eye, t_p3D *vect, float *k);
void			cone(t_p3D *eye, t_p3D *vect, float *k);
void			plan(t_p3D *eye, t_p3D *vect, float *k);

void			rotate_img(t_p3D *point, t_p3D *rot, int invert);
void			calc_current_object(t_p3D *eye, t_p3D *vect, t_obj *obj, float *tab);
void			calc_rtv1(t_env *e);

int			mult_color(int color, float prec);
int			add_color(int color, int color_2);

int			shadow_cast(t_env *e, t_p3D *spot, int color);

#endif
