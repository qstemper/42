# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/29 11:55:44 by qstemper          #+#    #+#              #
#    Updated: 2016/10/13 10:05:01 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCF = gcc
CF = -Wall -Werror -Wextra
EXE = ft_ls

INC = headers

SRC =	srcs/av.c			srcs/dir.c			srcs/error.c \
		srcs/fmt_mode.c		srcs/fmt_name.c		srcs/fmt_time.c	\
		srcs/ft_intlen.c	srcs/get_opt.c 		srcs/ls_avsort.c \
		srcs/ls_print.c		srcs/ls_sort.c		srcs/main.c \
		srcs/name.c			srcs/select.c		srcs/tree.c

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
	@echo "\t\t$(C_OK)Binary Created$(C_NO)"
	@$(CC) $(CF) -o $(EXE) -L $(LIBDIR) $(LIB) -L $(FTPDIR) $(FTP) $^

%.o : %.c
	@$(CC) $(CF) -c $< -o $@ -I $(INC)

$(LIBA) :
	@echo "\t\t$(C_OK)$(LIBA) Created$(C_NO)"
	@make -C $(LIBDIR)
$(FTPA) :
	@echo "\t\t$(C_OK)$(FTPA) Created$(C_NO)"
	@make -C $(FTPDIR)

clean :
	@echo "\t\t$(C_OK)Erasing all objects files$(C_NO)"
	@rm -rf $(OBJ)
	@make clean -C $(LIBDIR)
	@make clean -C $(FTPDIR)

fclean : clean
	@echo "\t\t$(C_OK)Erasing binary && librairies$(C_NO)"
	@rm -rf $(EXE)
	@make -C $(LIBDIR) fclean
	@make -C $(FTPDIR) fclean

re : fclean all
