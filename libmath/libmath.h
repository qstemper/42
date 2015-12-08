/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:41:23 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/08 10:55:51 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H

# define LIBMATH_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define PI 3.14159265

float	nb_digit(float x);
float	absolute(float x);
float	max(float x, float y);
float	max3(float x, float y, float z);
float	min(float x, float y);
float	min3(float x, float y, float z);
float	median(float x, float y, float z);
float	square(float x);
float	power(float x, int pow);
float	root(float x);
float	res_0_deg(float c);
float	res_1_deg(float b, float c);
float	res_2_deg_sol1(float a, float b, float c);
float	res_2_deg_sol2(float a, float b, float c);
float	absolute(float x);
float	arctan(float x);
float	arccos(float x);
float	arcsin(float x);
float	tangente(float x);
float	cosinus(float x);
float	sinus(float x);

#endif
