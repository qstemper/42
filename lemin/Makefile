# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/06 12:06:13 by qstemper          #+#    #+#              #
#    Updated: 2017/04/14 12:07:32 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = lem-in

INC = includes

SRC =	del_tab.c			destroy.c			dump_graph.c \
		dump_sol.c			ft_get_opt.c		get_lem.c \
		get_next_line.c		get_path.c			get_sol.c \
		global.c			lemin.c				main.c \
		meta_tool.c			neig.c				parse_hall.c \
		parse_pop.c			parse_room.c		parse_tag.c \
		parsing.c			play.c				prog_info.c \
		resolve.c			save_path.c			tool.c

OBJ = $(SRC:.c=.o)

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

all : $(LIBA) $(FTPA) $(DIR_OBJ) $(NAME)

$(NAME) : $(addprefix obj/, $(OBJ))
	@$(CC) $(CF) -o $(NAME) $^ -L $(LIBDIR) $(LIB) -L $(FTPDIR) $(FTP)
	@echo "\t\t$(C_OK)Binary Created$(C_NO)"

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
	@make -C $(LIBDIR) fclean
	@make -C $(FTPDIR) fclean

re : fclean all
