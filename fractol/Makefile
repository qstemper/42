CC = gcc
CF = -Wall -Werror -Wextra
EXE = fractol
EXE_C = fractol_cap

INC = headers

SRCS = fractol.c\
       mandelbrot.c\
       julia.c\
       dragon_curve.c

OBJ = $(SRCS:.c=.o)

LIB = libft.a
LIBM = libmath.a
MLX = libmlx.a
MLX_CAP = libmlxt.a

LIBFT = -lft
LIBMATH = -lmath
LIB_MLX = -lmlx
LIB_MLX_CAP = -lmlxt

LIBFT_DIR = libft
LIBMATH_DIR = libmath
MLX_DIR = mini_libx
MLX_DIR_CAP = minilibx_macos

FRAME = -framework OpenGL -framework AppKit

all : $(LIB) $(LIBM) $(MLX) $(EXE)
cap : $(LIB) $(LIBM) $(MLX_CAP) $(EXE_C)

$(EXE) : $(OBJ)
	$(CC) $(CF) -o $(EXE) -I $(INC) -I $(MLX_DIR) -L $(LIBFT_DIR) $(LIBFT) -L $(LIBMATH_DIR) $(LIBMATH) -L $(MLX_DIR) $(LIB_MLX) $^ $(FRAME)
$(EXE_C) : $(OBJ)
	$(CC) $(CF) -o $(EXE_C) -I $(INC) -I $(MLX_DIR_CAP) -L $(LIBFT_DIR) $(LIBFT) -L $(LIBMATH_DIR) $(LIBMATH) -L $(MLX_DIR_CAP) $(LIB_MLX_CAP) $^ $(FRAME)

$(LIB) :
	make -C $(LIBFT_DIR)
$(LIBM) :
	make -C $(LIBMATH_DIR)
$(MLX) :
	make -C $(MLX_DIR)
$(MLX_CAP) :
	make -C $(MLX_DIR_CAP)

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMATH_DIR)
	make clean -C $(MLX_DIR)
clean_cap :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMATH_DIR)
	make clean -C $(MLX_DIR_CAP)

fclean : clean
	rm -rf $(EXE)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMATH_DIR) fclean
fclean_cap : clean_cap
	rm -rf $(EXE_C)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMATH_DIR) fclean

re : fclean all
re_cap : fclean_cap cap
