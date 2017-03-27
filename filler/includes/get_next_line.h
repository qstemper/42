/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:13:45 by qstemper          #+#    #+#             */
/*   Updated: 2017/03/22 14:32:51 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE_GNL 42
# define MY_SIZE BUFF_SIZE_GNL + 1
# define OPENED_FILE_LIMIT 256

int		get_next_line(int const fd, char **line);

#endif
