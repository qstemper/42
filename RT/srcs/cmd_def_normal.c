/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_define_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:58:11 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/18 18:23:10 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void					cmd_def_norm_x(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->normal.x = ft_atoi(line[0]);
	else
		ft_printf("%s normal x", MSG_CMD_DEF);
}

void					cmd_def_norm_y(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->normal.y = ft_atoi(line[0]);
	else
		ft_printf("%s normal y", MSG_CMD_DEF);
}

void					cmd_def_norm_z(t_pars *pars, char **line)
{
	if (pars->last_type == LAST_OBJ)
		e->e_scene->scene->obj->normal.z = ft_atoi(line[0]);
	else
		ft_printf("%s normal y", MSG_CMD_DEF);
}
