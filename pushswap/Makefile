# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:58:48 by sbenning          #+#    #+#              #
#*   Updated: 2015/12/13 20:18:19 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC =			gcc

FLAGS =			-Wall -Wextra -Werror

NAME =			push_swap

HEADERS =		includes

SRC =			srcs/main.c\
				srcs/pushswap.c\
				srcs/reverse.c\
				srcs/nosort.c\
				srcs/sort.c\
				srcs/roll.c\
				srcs/getopt.c\
				srcs/simple_op.c\
				srcs/mult_op.c\
				srcs/debug.c\
				srcs/error.c

OBJ =			$(SRC:.c=.o)

LIBFT =			libft.a
LIBFT_DIR =		lib/ft
LIB =			-lft

DEPEND =		$(HEADERS)/pushswap.h

C_OK =			\x1b[32;01m
C_NO =			\x1b[0m


all : $(LIBFT) $(NAME)

$(NAME) : $(OBJ)
	@$(CC) -o $@ $^ -L $(LIBFT_DIR) $(LIB)
	@echo "\t\t$(C_OK)Binary created$(C_NO)"

$(LIBFT) :
	@make -C $(LIBFT_DIR)
	@echo "\t\t$(C_OK)$(LIBFT) created$(C_NO)"

%.o : %.c $(DEPEND)
	@$(CC) $(FLAGS) -o $@ -I $(LIBFT_DIR)/$(HEADERS) -I $(HEADERS) -c $<

clean:
	@echo "\t\t$(C_OK)Erasing all objects files$(C_NO)"
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "\t\t$(C_OK)Erasing binary && librairies$(C_NO)"
	@rm -f $(NAME)
	@rm -f $(LIBFT_DIR)/$(LIBFT)

re: fclean all
