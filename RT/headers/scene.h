/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:22:35 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/14 02:17:00 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct		s_scene
{
	struct s_cam	cam;
	struct s_cam	res_cam;
	int		width;
	int		height;
	struct s_obj	*obj;
	struct s_light	*light;
	float			diaph;
	int				recurs;
	unsigned int	if_name;
}					t_scene;

#endif
