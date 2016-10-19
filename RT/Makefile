# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/13 07:09:34 by qstemper          #+#    #+#              #
#    Updated: 2016/10/16 12:50:24 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CF = -Wall -Werror -Wextra
EXE = rt

INC = headers

SRCS =	cam_init.c		cam_move.c		cmd_add1.c		cmd_add2.c		cmd_obj.c \
	cmd_cam.c		cmd_def1.c		cmd_def2.c		cmd_def3.c		cmd_def4.c \
	cmd_def_color.c		cmd_def_normal.c	cmd_def_rotation.C	cmd_def_vx.c		cmd_def_vy.c \
	cmd_def_vz.c		cmd_editing.c		cmd_export.c		cmd_if_name.c		cmd_list.c \
	cmd_recurs.C		cmd_remove.c		cmd_res.c		cmd_unblock.c		eq.c \
	export_img.c		export_scene1.c		export_scene2.c		get_norm.c		img_pixel.c \
	inter.c			inter_init.c		key_check.c		key_init.c		key_press.c \
	key_release.c		light_diaph.c		main.c			matrix.c		mouse.c \
	obj.c			pars1.c			pars2.c			pars_init.c		phong_shade1.c \
	phong_shade2.c		phong_shade3.c		ray_chg.c		res_img.c		res_thread.c \
	rt_init.c		small_pos.c		trace_ray.c

OBJ = $(SRCS:.c=.o)

LIB = -lft
LIBA = libft.a
LIBDIR = libft

MLX = -lmlx
MLXA = libmlx.a
MLXDIR = minilibx_macos

FTP = -lftprintf
FTPA = libft_printf.a
FTPDIR = ft_printf

FRAME1 = -framework OpenGL
FRAME2 = -framework AppKit

C_OK = \x1b[32;01m
C_NO = \x1b[0m

RSRC = $(addprefix srcs/, %.c)
ROBJ = $(addprefix obj/, %.o)

DIR = obj

all : $(LIBA) $(FTPA) $(MLXA) $(DIR) $(EXE)

$(EXE) :  $(addprefix obj/, $(OBJ))
	@$(CC) $(CF) -o $(EXE) -L $(LIBDIR) $(LIB) -L $(FTPDIR) $(FTP) -L $(MLXDIR) $(MLX) $^ $(FRAME1) $(FRAME2)
	@echo "\t\t$(C_OK)Binary Created$(C_NO)"

$(DIR) :
	@mkdir obj
	@echo -e "\t\t$(C_OK)Dir obj created$(C_NO)"

$(ROBJ) : $(RSRC)
	@$(CC) $(CF) -c $< -o $@ -I $(INC)

$(LIBA) :
	@make -C $(LIBDIR)
	@echo "\n\t\t$(C_OK)$(LIBA) Created$(C_NO)"
$(FTPA) :
	@echo "\n\t\t$(C_OK)$(FTPA) Created$(C_NO)"
	@make -C $(FTPDIR)
$(MLXA) :
	@echo "\n\t\t$(C_OK)$(MLXA) Created$(C_NO)"
	@make -C $(MLXDIR)

clean :
	@echo "\n\t\t$(C_OK)Erasing All Objects Files$(C_NO)\n"
	@rm -rf $(ROBJ)
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
