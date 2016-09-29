# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/29 11:55:44 by qstemper          #+#    #+#              #
#    Updated: 2016/09/29 13:00:01 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCF = gcc -Wall -Werror -Wextra
NAME = ft_ls

INC = headers

SRC = avsort.c \
	  dir.c \
	  error.c \
	  fmt_mode.c \
	  fmt_name \
	  fmt_time.c \
	  ft_intlen.c \
	  get_opt.c \
	  ls_avsort \
	  ls_print.c \
	  ls_sort.c \
	  name.c \
	  select.c \
	  tree.c \
	  main.c

OBJ = $(SRC:.c=.o)

LIB = libft.a
LIBFT = -lft
LIBFT_DIR = libft

DEPEND = $(HEADERS)/ft_ls.h

all : $(LIB) $(NAME)

$(NAME) : $(OBJ)
	$(CCF) -o $@ $^ -L $(LIBFT_DIR) $(LIBFT)

$(LIB) :
	make -C $(LIBFT_DIR)

%.o : %.c $(DEPEND)
	$(CCF) -o $@ -I $(LIBFT_DIR)/$(HEADERS) -I $(HEADERS) -c $<

clean :
	rm -f $(OBj)
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIB)

re : flcean all
