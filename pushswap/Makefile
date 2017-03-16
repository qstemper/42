CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap

INC = includes

SRC =	main.c		pushswap.c	reverse.c	nosort.c \
	sort.c		roll.c		getopt.c	simple_op.c \
	mult_op.c 	debug.c		error.c

OBJ = $(SRC:.c=.o)

LIBA = libft.a
LIBDIR = libft
LIB = -lft

FTPA = libftprintf.a
FTP = -lftprintf
FTPDIR = ft_printf

DIR_OBJ = obj

C_OK = \x1b[32;01m
C_NO = \x1b[0m

RSRC = $(addprefix srcs/, %.c)
ROBJ = $(addprefix obj/, %.o)

all : $(LIBA) $(FTPA) $(DIR_OBJ) $(NAME)

$(NAME) : $(addprefix obj/, $(OBJ))
	@$(CC) $(CF) -o $(NAME) $^ -L $(LIBDIR) $(LIB) -L $(FTPDIR) $(FTP)
	@echo "\t\t$(C_OK)Binary Created$(C_NO)"

$(ROBJ) : $(RSRC)
	@$(CC) $(CF) -c $< -o $@ -I $(INC) -I $(LIBDIR)/$(INC) -I $(FTPDIR)/headers

$(LIBA) :
	@make -C $(LIBDIR)
	@echo "\t\t$(C_OK)$(LIBA) created$(C_NO)"
$(FTPA) :
	@make -C $(FTPDIR)
	@echo "\t\t$(C_OK)$(FTPA) created$(C_NO)"

$(DIR_OBJ) :
	@mkdir obj
	@echo "\t\t$(C_OK)Dir obj created$(C_NO)"

clean :
	@echo "\t\t$(C_OK)Erasing all objects files$(C_NO)"
	@rm -Rf obj
	@make clean -C $(LIBDIR)
	@make clean -C $(FTPDIR)

fclean : clean
	@echo "\t\t$(C_OK)Erasing binary && librairies$(C_NO)"
	@rm -Rf $(NAME)
	@make -C $(LIBDIR) fclean
	@make -C $(FTPDIR) fclean

re : fclean all
