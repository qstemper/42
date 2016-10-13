/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:22:14 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/13 08:51:38 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "headers/libft.h"
# include "headers/mlx.h"
# include "headers/ft_printf.h"
# include "headers/camera.h"
# include "headers/interpreter.h"
# include "headers/keyboard.h"
# include "headers/"
# include "headers/"
# include "headers/"
# include "headers/"
# include "headers/"
# include "headers/"
# include "headers/"
# include "headers/"
# include "headers/"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define SPHERE "sphere"
# define CONE "cone"
# define CYL "cylinder"
# define PLANE "plane"
# define LIGHT "light"

# define MSG_MEM	"Memory Allocation Failed" 
# define OBJ_ERROR	"Type Object Unknown"
# define OBJ_USE	"Usage : \n\tadd <object_type>"

# define ESC		53

# define CROSS		17
# define MASK_CQUIT	(1L<<17)

/*
***
*/

#endif
