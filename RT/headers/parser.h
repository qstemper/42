/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 15:09:15 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 18:34:56 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define COMMENT		'#'

# define LAST_NONE		0
# define LAST_CAM		1
# define LAST_LIGHT		2
# define LAST_OBJ		3

# define MSG_CMD_DEF	"ERROR ! Orphan Property :"

typedef struct			s_pars
{
	int					last_type;
	struct s_pars_cmd	*cmd;
}						t_pars;

typedef struct			s_pars_cmd
{
	char				*tok;
	int					indent_lvl;
	void				(*callback)(struct s_pars *, char **);
	struct s_oars_cmd	*next;
}						t_pars_cmd;

void					parse(char *file);
void					init_pars_scene(t_pars *pars);


/*
***					cmd_add_obj.c && cmd_cam.c
*/

void					cmd_add_sphere(t_pars *pars);
void					cmd_add_cone(t_pars *pars);
void					cmd_add_cyl(t_pars *pars);
void					cmd_add_plane(t_pars *pars);
void					cmd_add_light(t_pars *pars);
void					cmd_cam(t_pars *pars);

/*
***					cmd_def_vx.c
*/

void					cmd_def_vx_x(t_pars *pars, char **line);
void					cmd_def_vx_y(t_pars *pars, char **line);
void					cmd_def_vx_z(t_pars *pars, char **line);

/*
***					cmd_def_vy.c
*/

void					cmd_def_vy_x(t_pars *pars, char **line);
void					cmd_def_vy_y(t_pars *pars, char **line);
void					cmd_def_vy_z(t_pars *pars, char **line);

/*
***					cmd_def_vz.c
*/

void					cmd_def_vz_x(t_pars *pars, char **line);
void					cmd_def_vz_y(t_pars *pars, char **line);
void					cmd_def_vz_z(t_pars *pars, char **line);

/*
***					cmd_def_color.c
*/

void					cmd_def_color(t_pars *pars, char **line);
void					cmd_def_red(t_pars *pars, char **line);
void					cmd_def_green(t_pars *pars, char **line);
void					cmd_def_blue(t_pars *pars, char **line);

/*
***					cmd_def1.c
*/

void					cmd_def_ambient(t_pars *pars, char **line);
void					cmd_def_if_name(t_pars *pars, char **line);
void					cmd_def_diaph(t_pars *pars, char **line);
void					cmd_def_diffuse(t_pars *pars, char **line);
void					cmd_def_intens(t_pars *pars, char **line);

/*
***					cmd_def2.c
*/

void					cmd_def_opacity(t_pars *pars, char **line);
void					cmd_def_radius(t_pars *pars, char **line);
void					cmd_def_recurs(t_pars *pars, char **line);
void					cmd_def_mirror(t_pars *pars, char **line);

/*
***					cmd_def3.c
*/

void					cmd_def_height(t_pars *pars, char **line);
void					cmd_def_width(t_pars *pars, char **line);
void					cmd_def_reflec(t_pars *pars, char **line);
void					cmd_def_refrac(t_pars *pars, char **line);

/*
***					cmd_def_rotation.c
*/

void					cmd_def_rot_x(t_pars *pars, char **line);
void					cmd_def_rot_y(t_pars *pars, char **line);
void					cmd_def_rot_z(t_pars *pars, char **line);

/*
***					cmd_def_normal.c
*/

void					cmd_def_norm_x(t_pars *pars, char **line);
void					cmd_def_norm_y(t_pars *pars, char **line);
void					cmd_def_norm_z(t_pars *pars, char **line);

/*
***					cmd_def4.c
*/

void					cmd_def_x(t_pars *pars, char **line);
void					cmd_def_y(t_pars *pars, char **line);
void					cmd_def_z(t_pars *pars, char **line);

#endif
