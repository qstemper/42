/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:22:14 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 09:40:19 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "headers/libft.h"
# include "headers/mlx.h"
# include "headers/ft_printf.h"
# include "headers/cam.h"
# include "headers/inter.h"
# include "headers/key.h"
# include "headers/light.h"
# include "headers/matrix.h"
# include "headers/mouse.h"
# include "headers/obj.h"
# include "headers/pars.h"
# include "headers/ray.h"
# include "headers/scene.h"
# include "headers/test.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <pthread.h>

# define DEF_WIDTH	1300
# define DEF_HEIGHT	900
# define PLANE_PLOT		1000
# define RES_SPLIT		4
# define RES_PREC		2

# define OBJ			"Object"
# define IMG			"Image"
# define SCENE			"Scene"
# define CAM			"Cam"

# define SPHERE			"Sphere"
# define CONE			"Cone"
# define CYL			"Cylinder"
# define PLANE			"Plane"
# define LIGHT			"Light"

# define LIST			"list"
# define REM			"remove"
# define ADD			"add"
# define EXPORT			"export"
# define IF_NAME		"if_name"
# define RES			"res"
# define EDIT			"edit"
# define REC			"recurs"
# define BLOCK			"unblock"

# define MSG_MEM		"Memory Allocation Failed"
# define MSG_MLX		"Mlx Init Failed"
# define MSG_WIN		"Window Creation Failed"
# define MSG_IMG		"Image Creation Failed"
# define MSG_DATA		"Data Access Failed"
# define MSG_LINE		"Line Inexistant"
# define MSG_THREAD		"Unable To Create Thread"
# define MSG_CMD		"Unknown Command"

# define OBJ_ERROR		"Object Type Unknown"
# define OBJ_LOST		"Object Not Found"

# define USE_OBJ		"Usage :\n\tadd <object_type>"
# define USE_EXPORT		"Usage :\n\texport [img|scene] <file>"
# define USE_REC		"Usage :\n\trecurs <value : 1 - 40>"
# define USE_ALIAS		"Usage :\n\tif_name <value : 1 - 40>"
# define USE_REM		"Usage :\n\tremove <obj_addr>"

# define ESC			53
# define L_ARROW		123
# define R_ARROW		124
# define D_ARROW		125
# define U_ARROW		126
# define PAGE_UP		116
# define PAGE_DOWN		121
# define NUM_PLUS		69
# define NUM_MINUS		78
# define NUM_MULT		67
# define NUM_DIV		75
# define DEL			51
# define SHIFT_L		257
# define SHIFT_R		258
# define CTRL_L			256
# define CTRL_R			269
# define ALT_L			261
# define ALT_R			262
# define TAB			48
# define SPACE			49
# define W				13
# define A				0
# define S				1
# define D				2

# define LEFT_C			1
# define RIGHT_C		2

# define KPRESS			2
# define KREL			3
# define BPRESS			4
# define BREL			5
# define MNOTIFY		6
# define CROSS			17
# define KPMASK			(1L<<0)
# define KRMASK			(1L<<1)
# define BPMASK			(1L<<2)
# define BRMASK			(1L<<3)
# define MNMASK			(1L<<6)
# define MASK_CQUIT		(1L<<17)

typedef struct				s_sup_vect
{
	t_vect					*light_vect;
	t_vect					*normal;
	t_vect					*reflect_light;
	t_vect					*cam;
}							t_sup_vect;

typedef	struct				s_env_scene
{
	t_scene					*scene;
	t_light_color			*res;
	pthread_t				*res_thread;
	int						run_thread;
}							t_env_scene;

typedef struct				s_mlx
{
	void					*mlx;
	void					*win;
	void					*img;
	int						bpp;
	int						sizeline;
	int						endian;
	char					*data;
}							t_mlx;

typedef struct				s_frame
{
	clock_t					img_refresh;
	clock_t					light_refresh;
	clock_t					scene_refresh;
	int						block;
	int						fast_mode;
}							t_frame;

typedef struct				s_event
{
	t_key					key;
	t_obj					*select_obj;
	int						mouse;
	int						x;
	int						y;
}							t_event;

typedef struct				s_env
{
	struct s_mlx			mlx;
	struct s_env_scene		e_scene;
	struct s_frame			frame;
	struct s_event			event;
	t_inter					inter;
	pthread_t				inter_thread;
	int						calc_light;
}							t_env;

typedef struct				s_thread_input
{
	unsigned int			x1;
	unsigned int			x2;
	unsigned int			y1;
	unsigned int			y2;
	int						thread_nb;
}							t_thread_input;

/*
***						export_img.c && export_scene.c	
*/

void						export_img(int file);
void						export_scene(int file);

/*
***						export_scene2.c
*/

void						display_sphere_prp(t_obj *sphere, int file);
void						display_cone_prp(t_obj *cone, int file);
void						display_cyl_prp(t_obj *cyl, int file);
void						display_plane_prp(t_obj *plane, int file_;

/*
***						light_diaph.c
*/

int							light_diaph(t_light_color *light, float diaph);

/*
***						phong_shade1.c && phong_shade2.c && phong_shade3.c
*/

void						phong_shade(t_ray *ray);
float						phong_light(t_ray *ray);
t_point						pt_ray_intersec(t_ray *ray, float f);
int							pt_lighted(t_obj *obj, t_point pt, t_light *light);
void						phong_cam(t_sup_vect *vect, t_point intersec, \
	t_env *e);

/*
***						img_pixel.c && trace_ray.c
*/

void						img_pixel(int x, int y, int color);
t_ray						get_ray_from_point(float i, float j);
void						trace_ray(t_ray *ray, t_env *e, t_obj *to_ignore, \
		int recurs);

/*
***						res_thread.c && res_img.c
*/

int							res_thread(t_thread_input *in, t_env *e);
int							res_light(int x, int y, t_light_color *light, \
		t_env *e);
void						fast_res_light(int x, int y, \
		t_light_color *light, t_env *e);
void						clean_res_light(int x, int y, t-env *e);
void						img_res(t_env *e);

/*
***						main.c && rt_init.c
*/

int							update_img(t_env *e);
int							mlx_init;
void						env_init;





void						trace_ray_predef(t_ray *ray, int calc_light, t_obj *obj);

void						update_res_cam(t_cam *res, t_cam *cam);

#endif
