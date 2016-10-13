# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/13 07:09:34 by qstemper          #+#    #+#              #
#    Updated: 2016/10/13 14:49:06 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CF = -Wall -Werror -Wextra
EXE = fractol

INC = headers

SRCS = 

OBJ = $(SRCS:.c=.o)

LIB = -lft
LIBA = libft.a
LIBDIR = libft
LIBALL = $(LIBDIR) $(LIB)

MLX = -lmlx
MLXA = libmlx.a
MLXDIR = minilibx_macos
MLXALL = $(MLXDIR) $(MLX)

FTP = -lftprintf
FTPA = libft_printf.a
FTPDIR = ft_printf
FTPALL = $(FTPDIR) $(FTP)

FRAME1 = -framework OpenGL
FRAME2 = -framework AppKit
FRAMEALL = $(FRAME1) $(FRAME2) 

C_OK = \x1b[32;01m
C_NO = \x1b[0m

$(EXE) : $(OBJ)
	@echo "\t\t$(C_OK)Creating Binary$(C_NO)"
	@$(CC) $(CF) -o $(EXE) -L $(LIBALL) -L $(FTPALL) -L $(MLXALL) $^ $(FRAMEALL)

%.o : %.c
	@$(CC) $(CF) -c $< -o $@ -I $(INC)

$(LIBA) :
	@echo "\n\t\t$(C_OK)Creating $(LIBA)$(C_NO)"
	@make -C $(LIBDIR)
$(FTPA) :
	@echo "\n\t\t$(C_OK)Creating $(FTPA)$(C_NO)"
	@make -C $(FTPDIR)
$(MLXA) :
	@echo "\n\t\t$(C_OK)Creating $(MLXA)$(C_NO)"
	@make -C $(MLXDIR)

clean :
	@echo "\n\t\t$(C_OK)Erasing All Objects Files$(C_NO)\n"
	@rm -rf $(OBJ)
	@make clean -C $(LIBDIR)
	@make clean -C $(FTPDIR)
	@make clean -C $(MLXDIR)

fclean : clean
	@echo "\n\t\t$(C_OK)Erasing .exe && Librairies$(C_NO)\n"
	@rm -rf $(EXE)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FTPDIR) fclean 
	@make -C $(MLXDIR) fclean

re : fclean all
