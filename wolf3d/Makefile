# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 16:02:46 by qstemper          #+#    #+#              #
#    Updated: 2016/10/06 07:43:26 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCF = gcc -Wall -Werror -Wextra
EXE = wolf3d

INC = headers

SRCS = draw.c \
	   error.c \
	   get_next_line.c \
	   init.c \
	   key.c \
	   loop_hook.c \
	   move.c \
	   ray.c \
	   read.c \
	   main.c

OBJ = $(SRCS:.c=.o)

LIB = libft.a
MLX = libmlxt.a

LIBFT = -lft
LIB_MLX = -lmlxt

LIBFT_DIR = libft
MLX_DIR = minilibx_macos

FRAME = -framework OpenGL -framework AppKit

all : $(LIB) $(MLX) $(EXE)

$(EXE) : $(OBJ)
	$(CC) -o $(EXE) -I $(INC) -I $(MLX_DIR) -L $(LIBFT_DIR) $(LIBFT) -L $(MLX_DIR) $(LIB_MLX) $^ $(FRAME)

$(LIB) :
	make -C $(LIBFT_DIR)
$(MLX) :
	make -C $(MLX_DIR)

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean : clean
	rm -rf $(EXE)
	make -C $(LIBFT_DIR) fclean

re : fclean all
