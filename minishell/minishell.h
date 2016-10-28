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

typedef struct		termios t_termios;

/*
***		main.c
*/

char			*get_env(char **env; char *key);

#endif
