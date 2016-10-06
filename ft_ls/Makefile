# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/29 11:55:44 by qstemper          #+#    #+#              #
#    Updated: 2016/10/06 08:16:01 by qstemper         ###   ########.fr        #
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

LIBFTP = libft_printf.a
FTP = -lft_printf
FTP_DIR = ft_printf

all : $(LIBFT) $(LIBFTP) $(NAME)

$(EXE) : $(OBJ)
	$(CCF) -o $(EXE) -I $(INC) -L $(LIBFT_DIR) $(LIB) -L $(FTP_DIR) $(FTP) $^

$(LIBFT) :
	make -C $(LIBFT_DIR)
$(LIBFTP) :
	make -C $(FTP_DIR)

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FTP_DIR)

fclean : clean
	rm -rf $(EXE)
	make -C $(LIBFT_DIR) fclean
	make -C $(FTP_DIR) fclean

re : fclean all
