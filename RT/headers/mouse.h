/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:57:39 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 14:58:57 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

int		mouse_press(int button, int x, int y);
int		mouse_release(int button, int x, int y);
int 	motion_notify(int x, int y, t_env *end);

#endif
