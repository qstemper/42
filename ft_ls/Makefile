# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/29 11:55:44 by qstemper          #+#    #+#              #
#    Updated: 2016/10/12 20:03:55 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCF = gcc
CF = -Wall -Werror -Wextra
EXE = ft_ls

INC = headers

SRC = $(wildcard srcs/*.c)

#SRC =	av.c			dir.c			error.c			fmt_mode.c \
#		fmt_name.c		fmt_time.c		ft_intlen.c		get_opt.c \
#		ls_avsort.c		ls_print.c		ls_sort.c		name.c \
#		select.c		tree.c			main.c

OBJ = $(SRC:.c=.o)

LIBA = libft.a
LIB = -lft
LIBDIR = libft

FTPA = libftprintf.a
FTP = -lftprintf
FTPDIR = ft_printf

C_OK = \x1b[32;01m
C_NO = \x1b[0m

all : $(LIBA) $(FTPA) $(EXE)

$(EXE) : $(OBJ)
	@$(CC) $(CF) -o $(EXE) -I $(INC) -L $(LIBDIR) $(LIB) -L $(FTPDIR) $(FTP) $^

$(LIBA) :
	@echo "\n\t\t$(C_OK)Creating $(LIBA)$(C_NO)\n"
	@make -C $(LIBDIR)
$(FTPA) :
	@echo "\n\t\t$(C_OK)Creating $(FTPA)$(C_NO)\n"
	@make -C $(FTPDIR)

clean :
	@echo "\n\t\t$(C_OK)Erasing all objects files$(C_NO)\n"
	@rm -rf $(OBJ)
	@make clean -C $(LIBDIR)
	@make clean -C $(FTPDIR)

fclean : clean
	@echo "\n\t\t$(C_OK)Erasing .exe && librairies$(C_NO)\n"
	@rm -rf $(EXE)
	@make -C $(LIBDIR) fclean
	@make -C $(FTPDIR) fclean

re : fclean all
