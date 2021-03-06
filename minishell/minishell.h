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
# define ERROR_ATTR			"Attribute Unknown"
# define ERROR_CD_HOME		"The Variable HOME Is Not Set Or Doesn't Exist"

# define ECHO_N				0x1
# define ENV_I				0x1
# define CD_L				0x1
# define CD_P				0x2
# define ERROR_BUILTIN_OPT	0x4

# define CHARSET_ECHO		"n"
# define CHARSET_CD			"LP"
# define CHARSET_ENV		"i"

# define ECHO				"echo"
# define EXIT				"exit"
# define CD					"cd"
# define ENV				"env"
# define SET_E				"setenv"
# define UNSET_E			"unsetenv"

# define IS(X, Y) ((Y & X) == X ? 1 : 0)

typedef struct		termios t_termios;
typedef struct		dirent t_dirent;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
***				pars.c && get.c
*/

char				*pars(char *str, char **env; int term_orig);
char				*get_env(char **env; char *key, t_term_orig);
int					get_opt(const char *cset, int ac, char **av, char *err);
int					skip_opt(int ac, char **av);
int					is_env(char **env, char *key);

/*
***				error.C
*/

void				error(char *str, t_term_orig);
void				error_builtin(char *str);
void				error_pars(char *str);
void				error_usage(int error);

/*
***				builtin.c && builtin_env.cc
*/

void				builtin_echo(int ac, char **tab);
void				builtin_exit(t_termios term_orig);
void				builtin_env(int ac, char **av, char **env, \
	t_termios term_orig);

/*
***				builtin_cd.c && builtin_cd_env.c && builtin_cd_cond.c
*/

void				builtin_cd(int ac, char **tab, char **env, t_termios term_orig);
char				**check_home(int ac, char **env, t_termios term_orig);
char				**check_pwd(int ac, char **env, t_termios term_orig);
int					check_oldpwd(char **env);
void				conv_tilde(char **env, char **abs_path, char **tab);
void				conv_point(char **abs_path, char **tab);

/*
***				builtin_setenv.c && builtin_unsetenv.c
*/

char				**builtin_setenv(int ac, char **tab, char **env);
char				**if_ret_null(char **env, char *str, char *value, int i);
char				**if_ret_not_null(char **env, char *str, char *value)
void				builtin_unsetenv(int ac, char **tab, char **env)

#endif
