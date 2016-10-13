/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:22:35 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 16:25:19 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct		s_scene
{
	struct s_cam	cam;
	struct s_cam	res_cam;
	unsigned int	view_width;
	unsigned int	view_height;
	struct s_obj	*obj;
	struct s_light	*light;
	float			diaph;
	int				recurs;
	unsigned int	antialias;
}					t_scene;

#endif
