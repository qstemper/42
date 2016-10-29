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

# define ERROR_KEY	"The Key You Are Searching Doesn't Exist"
# define ERROR_TERM	"Failed In Checking Termios"
# define ERROR_READ	"Failed To Read The Line"
# define ERROR_MALLOC	"Memory Allocation Failed"
# define ERROR_PARS	"Error In Parsing"

# define ECHO		"echo"
# define CD		"cd"
# define SET_E		"setenv"
# define UNSET_E	"unsetenv"
# define ENV		"env"
# define EXIT		"exit"

typedef struct		termios t_termios;
typedef struct		dirent t_dirent;

/*
***		main.c
*/

char			*get_env(char **env; char *key);

#endif
