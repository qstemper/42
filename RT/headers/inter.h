/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 07:56:23 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 21:58:31 by qstemper         ###   ########.fr       */
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
	void			(*callback)(char **);
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

/*
***					cmd_if_name.c && cmd_editing.c && cmd_export && cmd_list.c
*/

void				cmd_if_name(char **line);
void				cmd_editing(void);
void				cmd_export(char **line);
void				cmd_list.c(void);

/*
***					cmd_recurs.c && cmd_remove.c && cmd_res.c && cmd_unblock.c
*/

void				cmd_recurs(char **line);
void				cmd_remove(char **line);
void				cmd_res(void);
void				cmd_unblock(char **line);

/*
***					inter_init.ci && inter.c
*/

void				inter_init_cmd(t_inter *inter);
int					create_inter_thread(void);

void				export_img(int file);
void				export_scene(int file);

#endif
