CC = gcc
CF = -Wall -Werror -Wextra
EXE = ft_printf 
EXE_C = ft_printf

INC = headers

SRCS = 

OBJ = $(SRCS:.c=.o)

LIB = libft.a
LIBFT = -lft
LIBFT_DIR = libft

all : $(LIB) $(EXE)
cap : $(LIB) $(EXE_C)

$(EXE) : $(OBJ)
	$(CC) $(CF) -o $(EXE) -I $(INC) -L $(LIBFT_DIR) $(LIBFT) $^
$(EXE_C) : $(OBJ)
	$(CC) $(CF) -o $(EXE_C) -I $(INC) -L $(LIBFT_DIR) $(LIBFT) $^

$(LIB) :
	make -C $(LIBFT_DIR)

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
clean_cap :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -rf $(EXE)
	make -C $(LIBFT_DIR) fclean
fclean_cap : clean_cap
	rm -rf $(EXE_C)
	make -C $(LIBFT_DIR) fclean

re : fclean all
re_cap : fclean_cap cap
