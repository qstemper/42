# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 18:51:43 by qstemper          #+#    #+#              #
#    Updated: 2015/12/03 12:18:40 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
EXEC = fdf

INCLUDES = headers

SRCS = get_next_line/get_next_line.c\
	   lexer/lexer.c\
	   lexer/lexer_check_token.c\
	   lexer/lexer_init.c\
	   fdf.c\
	   fdf_mlx.c

OBJ = $(SRCS:.c=.o)

LIB = libft.a
MLX = libmlx.a

LIBFT = -lft
LIB_MLX = -lmlx

LIBFT_DIR = libft
MLX_DIR = mini_libx

FRAME = -framework OpenGL -framework AppKit

all : $(EXEC)

$(EXEC) : $(OBJ) $(LIB) $(MLX)
	$(CC) $(CFLAGS) -o $(EXEC) -I $(INCLUDES) -L $(LIBFT_DIR) $(LIBFT) -L $(MLX_DIR) $(LIB_MLX) $(OBJ) $(FRAME)

$(LIB) :
	make -C $(LIBFT_DIR)
$(MLX) :
	make -C $(MLX_DIR)

%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean : clean
	rm -rf $(EXEC)
	make -C $(LIBFT_DIR) fclean

re : fclean all

#.PHONY : all clean fclean re mrproper
