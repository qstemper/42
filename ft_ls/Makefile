# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/29 11:55:44 by qstemper          #+#    #+#              #
#    Updated: 2016/10/16 12:49:35 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCF = gcc
CF = -Wall -Werror -Wextra
EXE = ft_ls

INC = headers

SRC =	av.c				dir.c				error.c \
	fmt_mode.c			fmt_name.c			fmt_time.c \
	ft_intlen.c			get_opt.c 			ls_avsort.c \
	ls_print.c			ls_sort.c			main.c \
	name.c				select.c			tree.c

OBJ = $(SRC:.c=.o)

LIBA = libft.a
LIB = -lft
LIBDIR = libft

FTPA = libftprintf.a
FTP = -lftprintf
FTPDIR = ft_printf

DIR_OBJ = obj

C_OK = \x1b[32;01m
C_NO = \x1b[0m

RSRC = $(addprefix srcs/, %.c)
ROBJ = $(addprefix obj/, %.o)

all : $(LIBA) $(FTPA) $(DIR_OBJ) $(EXE)

$(EXE) : $(addprefix obj/, $(OBJ))
	@$(CC) $(CF) -o $(EXE) -L $(LIBDIR) $(LIB) -L $(FTPDIR) $(FTP) $^
	@echo "\t\t$(C_OK)Binary Created$(C_NO)"

$(ROBJ) : $(RSRC)
	@$(CC) $(CF) -c $< -o $@ -I $(INC)

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
	@rm -Rf $(EXE)
	@make -C $(LIBDIR) fclean
	@make -C $(FTPDIR) fclean

re : fclean all
