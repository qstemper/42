# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 16:03:33 by qstemper          #+#    #+#              #
#    Updated: 2016/10/13 07:19:01 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CF = -Wall -Werror -Wextra
EXE = fractol

INC = headers

SRCS = apply_color.c\
       color_creating.c\
       draw_fractal.c\
       fractal.c\
       fractal_bis.c\
       event.c\
       tools.c\
       main.c

OBJ = $(SRCS:.c=.o)

LIB = libft.a
MLX_CAP = libmlxt.a

LIBFT = -lft
LIB_MLX_CAP = -lmlxt

LIBFT_DIR = libft
MLX_DIR_CAP = minilibx_macos

FRAME = -framework OpenGL -framework AppKit

all : $(LIB) $(MLX_CAP) $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(CF) -o $(EXE) -I $(INC) -I $(MLX_DIR_CAP) -L $(LIBFT_DIR) $(LIBFT) -L $(MLX_DIR_CAP) $(LIB_MLX_CAP) $^ $(FRAME)

$(LIB) :
	make -C $(LIBFT_DIR)
$(MLX_CAP) :
	make -C $(MLX_DIR_CAP)

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR_CAP)

fclean : clean
	rm -rf $(EXE)
	make -C $(LIBFT_DIR) fclean

re : fclean all
