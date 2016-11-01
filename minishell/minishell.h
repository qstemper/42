/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:14:28 by qstemper          #+#    #+#             */
/*   Updated: 2016/11/01 17:00:39 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>
# include <termios.h>
# include "ft_printf.h"
# include "libft.h"

# define ERROR_KEY			"The Key You Are Searching Doesn't Exist"
# define ERROR_TERM			"Failed In Checking Termios"
# define ERROR_READ			"Failed To Read The Line"
# define ERROR_MALLOC		"Memory Allocation Failed"
# define ERROR_PARS			"Error In Parsing"
# define ERROR_ATTRIB_ENV	"Illegal Attribute. Use i, P, S, u, v"
# define ERROR_VAR_ENV		"Variable Name Unknown"

# define ECHO				"echo"
# define CD					"cd"
# define EXIT				"exit"
# define ENV				"env"
# define SET_E				"setenv"
# define UNSET_E			"unsetenv"

typedef struct		termios t_termios;
typedef struct		dirent t_dirent;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_attr
{
	char			c;
	char			*name;
}					t_attr;

/*
***				get_env.c && env.c
*/

char				*get_env(char **env; char *key);
void				error(char *str);

/*
***				builtin1.c && builtin2.c
*/

void				builtin_echo(char **tab);
void				builtin_cd(char **env, char **tab);
void				builtin_exit(void);
void				builtin_env(char **env, char **tab);

#endif
