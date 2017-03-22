# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/22 09:40:05 by qstemper          #+#    #+#              #
#    Updated: 2017/03/22 17:27:31 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME_CHECK = checker

INC = includes

SRC =			main.c			pushswap.c		reverse.c		nosort.c \
				sort.c			roll.c			getopt.c		simple_op.c \
				mult_op.c	 	debug.c			error.c

SRC_CHECK =		checker.c			push.c			swap.c \
				rotate.c			rev_rot.c		global_ins.c \
				destroy.c			get_next_line.c

OBJ = $(SRC:.c=.o)
OBJ_CHECK = $(SRC_CHECK:.c=.o)

LIBA = libft.a
LIBDIR = libft
LIB = -lft

FTPA = libftprintf.a
FTP = -lftprintf
FTPDIR = ft_printf

DIR_OBJ = obj

C_OK = \x1b[32;01m
C_NO = \x1b[0m

RSRC = $(addprefix srcs/, %.c)
ROBJ = $(addprefix obj/, %.o)

all : $(LIBA) $(FTPA) $(DIR_OBJ) $(NAME) $(NAME_CHECK)

$(NAME) : $(addprefix obj/, $(OBJ))
	@$(CC) $(CF) -o $(NAME) $^ -L $(LIBDIR) $(LIB) -L $(FTPDIR) $(FTP)
	@echo "\t\t$(C_OK)Pushswap Binary Created$(C_NO)"

$(NAME_CHECK) : $(addprefix obj/, $(OBJ_CHECK))
	@$(CC) $(CF) -o $(NAME_CHECK) $^ -L $(LIBDIR) $(LIB) -L $(FTPDIR) $(FTP)
	@echo "\t\t$(C_OK)Checker Binary Created$(C_NO)"

$(ROBJ) : $(RSRC)
	@$(CC) $(CF) -c $< -o $@ -I $(INC) -I $(LIBDIR)/$(INC) -I $(FTPDIR)/headers

$(LIBA) :
	@make -C $(LIBDIR)
	@echo "\t\t$(C_OK)$(LIBA) created$(C_NO)"
$(FTPA) :
	@make -C $(FTPDIR)
	@echo "\t\t$(C_OK)$(FTPA) created$(C_NO)"

$(DIR_OBJ) :
	@mkdir obj
	@echo "\t\t$(C_OK)Dir obj created$(C_NO)"

clean :
	@echo "\t\t$(C_OK)Erasing all objects files$(C_NO)"
	@rm -Rf obj
	@make clean -C $(LIBDIR)
	@make clean -C $(FTPDIR)

fclean : clean
	@echo "\t\t$(C_OK)Erasing binary && librairies$(C_NO)"
	@rm -Rf $(NAME)
	@rm -Rf $(NAME_CHECK)
	@make -C $(LIBDIR) fclean
	@make -C $(FTPDIR) fclean

re : fclean all
