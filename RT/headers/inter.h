/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 07:56:23 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 08:57:46 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_H
# define INTER_H

typedef struct		s_inter
{
	char			**last_cmd;
	struct s_cmd	*cmd;
}					t_inter;

typedef struct		s_cmd
{
	char			*token;
	void			(*f)(char **);
	struct s_cmd	*next;
}					t_cmd;

/*
***					cmd_add.c && cmd_add2.c
*/

void				cmd_add(char **line);

void				add_sphere();
void				add_cyl();
void				add_cone();
void				add_plane();
void				add_light();



int					create_inter_thread();
void				inter_init_cmd(t_inter *inter);
void				cmd_list(char **line);
void				cmd_remove(char **line);
void				cmd_export(char **line);
void				cmd_antialias(char **line);
void				cmd_res(char **line);
void				cmd_editing(char **line);
void				cmd_recurs(char **line);
void				cmd_unblock(char **line);
void				export_img(int file);
void				export_scene(int file);

#endif
