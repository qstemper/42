# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/29 11:55:44 by qstemper          #+#    #+#              #
#    Updated: 2016/10/05 15:57:35 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCF = gcc -Wall -Werror -Wextra
EXE = ft_ls

INC = headers

SRC = av.c \
	  dir.c \
	  error.c \
	  fmt_mode.c \
	  fmt_name.c \
	  fmt_time.c \
	  ft_intlen.c \
	  get_opt.c \
	  ls_avsort.c \
	  ls_print.c \
	  ls_sort.c \
	  name.c \
	  select.c \
	  tree.c \
	  main.c

OBJ = $(SRC:.c=.o)

LIBFT = libft.a
LIB = -lft
LIBFT_DIR = libft

DEPEND = $(INC)/ft_ls.h

all : $(LIBFT) $(NAME)

$(EXE) : $(OBJ)
	$(CCF) -o $@ $^ -L $(LIBFT_DIR) $(LIB)

$(LIBFT) :
	make -C $(LIBFT_DIR)

%.o : %.c $(DEPEND)
	$(CCF) -o $@ -I $(LIBFT_DIR)/$(INC) -I $(INC) -c $<

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -rf $(EXEE)
	make -C $(LIBFT_DIR) fclean

re : fclean all
