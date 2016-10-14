/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:54:59 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/14 01:56:42 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

/*
***					matrix.c
*/

t_vect		matrix_vect_prod(float matrix[9], t_vect *a);
t_point		matrix_pt_prod(float matrix[9], t_point *a);
void		transfo_matrix(float matrix[9], t_vect *a, t_vect *y, t_vect *z);
void		invert_matrix(float matrix[9], float inv_matrix[9]);

#endif