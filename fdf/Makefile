# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 18:51:43 by qstemper          #+#    #+#              #
#    Updated: 2015/12/18 18:46:55 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = fdf
EXEC_CAP = fdf_cap

INCLUDES = headers

SRCS = get_next_line/get_next_line.c\
	   lexer/lexer.c\
	   lexer/lexer_check_token.c\
	   lexer/lexer_init.c\
	   fdf.c\
	   fdf_mlx.c\
	   fdf_key.c\
	   fdf_matrix.c\
	   fdf_view.c\
	   bresenham.c\
	   bres_dx_sup.c\
	   bres_dx_inf.c\
	   bres_dx_null.c

OBJ = $(SRCS:.c=.o)

LIB = libft.a
MLX = libmlx.a
MLX_CAP = libmlxt.a

LIBFT = -lft
LIB_MLX = -lmlx
LIB_MLX_CAP = -lmlxt

LIBFT_DIR = libft
MLX_DIR = mini_libx
MLX_DIR_CAP = minilibx_macos

FRAME = -framework OpenGL -framework AppKit

all : $(LIB) $(MLX) $(EXEC)
cap : $(LIB) $(MLX_CAP) $(EXEC_CAP)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) -I $(INCLUDES) -L $(LIBFT_DIR) $(LIBFT) -L $(MLX_DIR) $(LIB_MLX) $^ $(FRAME)
$(EXEC_CAP) : $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC_CAP) -I $(INCLUDES) -I $(MLX_DIR_CAP) -L $(LIBFT_DIR) $(LIBFT) -L $(MLX_DIR_CAP) $(LIB_MLX_CAP) $^ $(FRAME)


$(LIB) :
	make -C $(LIBFT_DIR)
$(MLX) :
	make -C $(MLX_DIR)
$(MLX_CAP) :
	make -C $(MLX_DIR_CAP)

%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
clean_cap :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR_CAP)


fclean : clean
	rm -rf $(EXEC)
	make -C $(LIBFT_DIR) fclean
fclean_cap : clean_cap
	rm -rf $(EXEC_CAP)
	make -C $(LIBFT_DIR) fclean


re : fclean all
re_cap : fclean_cap cap
