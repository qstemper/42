/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:22:14 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 21:13:56 by qstemper         ###   ########.fr       */
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

# define DEFAULT_WIDTH	1300
# define DEFAULT_HEIGHT	900
# define PLANE_PLOT		1000
# define RES_SPLIT		4
# define RES_PREC		2

# define OBJ			"Object"
# define IMG			"Image"
# define SCENE			"Scene"

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
# define MSG_LINE		"Line Inexistant"
# define MSG_THREAD		"Unable To Create Interpreter Thread"
# define OBJ_ERROR		"Object Type Unknown"
# define OBJ_LOST		"Object Not Found"
# define USE_OBJ		"Usage :\n\tadd <object_type>"
# define USE_EXPORT		"Usage :\n\texport [img|scene] <file>"
# define USE_REC		"Usage :\n\trecurs <value : 1 - 40>"
# define USE_ALIAS		"Usage :\n\tif_name <value : 1 - 40>"
# define USE_REM		"Usage :\n\tremove <obj_addr>"

# define ESC			53

# define CROSS			17
# define MASK_CQUIT		(1L<<17)

typedef	struct				s_env_scene
{
	t_scene					*scene;
	t_light_color			*rend;
	pthread_t				*rend_threads;
	int						run_threads;
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
	pthread_t				inter_thread
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
***
*/

int							update_image();
int							create_rend_thread(t_thread_input *in);
void						img_pixel(int x, int y, int color);
int							light_diaph(t_light_color *light, float diaph);
int							res_light(int x, int y, t_light_color *light);
void						fast_res_light(int x, int y, t_light_color *light);
void						clean_res_light(int x, int y);
void						img_res();
void						update_render_cam(t_cam *res, t_cam *cam);

#endif
