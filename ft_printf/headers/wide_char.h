/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 08:14:54 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/07 11:20:53 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDE_CHAR_H
# define WIDE_CHAR_H

# include "header.h"

# define MASK1 49280
# define MASK2 14712960
# define MASK3 4034953344

size_t	w_c_len(wchar_t *s);
void	wide_ctoa(wchar_t *wide_s, char *s);

#endif
