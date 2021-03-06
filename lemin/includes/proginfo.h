/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proginfo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:49:43 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/20 08:52:25 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGINFO_H
# define PROGINFO_H

# define PI_ISOPT(X, Y) (X & Y)
# define PI_SETOPT(X, Y) (X |= Y)
# define PI_UNSETOPT(X, Y) (X &= ~Y)

# include "libft.h"

typedef struct s_proginfo	t_proginfo;

struct						s_proginfo
{
	char					*name;
	int						arg_c;
	char					**arg_v;
	char					**env_p;
	unsigned long int		opt;
	int						oarg_c;
	char					**oarg_v;
	unsigned long int		err_t;
	void					*err_v;
	size_t					err_s;
	unsigned long int		meta_t;
	void					*meta_v;
	size_t					meta_s;
};

int							ft_getopt(int ac, char **av, char *charset);
void						proginfo_init(int arg_c, char **arg_v, \
								char **env_p, char *opt_charset);
t_proginfo					*proginfo(void);
void						proginfo_destroy(void);

#endif
