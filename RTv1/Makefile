CC = gcc
CF = -Wall -Werror -Wextra
EXE = rtv1
EXE_C = rtv1_cap

INC = headers

SRCS = event.c\
       img_draw.c\
       init.c\
       light_calc.c\
       main.c\
       mlx_init.c\
       obj_calc.c\
       obj_list.c\
       rotation.c\
       rtv1_draw.c\
       set_color.c\
       shadow_calc.c

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

all : $(LIB) $(MLX) $(EXE)
cap : $(LIB) $(MLX_CAP) $(EXE_C)

$(EXE) : $(OBJ)
	$(CC) $(CF) -o $(EXE) -I $(INC) -I $(MLX_DIR) -L $(LIBFT_DIR) $(LIBFT) -L $(MLX_DIR) $(LIB_MLX) $^ $(FRAME)
$(EXE_C) : $(OBJ)
	$(CC) $(CF) -o $(EXE_C) -I $(INC) -I $(MLX_DIR_CAP) -L $(LIBFT_DIR) $(LIBFT) -L $(MLX_DIR_CAP) $(LIB_MLX_CAP) $^ $(FRAME)

$(LIB) :
	make -C $(LIBFT_DIR)
$(MLX) :
	make -C $(MLX_DIR)
$(MLX_CAP) :
	make -C $(MLX_DIR_CAP)

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
clean_cap :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR_CAP)

fclean : clean
	rm -rf $(EXE)
	make fclean -C $(LIBFT_DIR)
fclean_cap : clean_cap
	rm -rf $(EXE_C)
	make fclean -C $(LIBFT_DIR)

re : fclean all
re_cap : fclean_cap cap
