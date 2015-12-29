NAME = libmath.a

CC = gcc
CF = -Wall -Wextra -Werror

SRCS = absolute.c\
       arccos.c\
       arcsin.c\
       arctan.c\
       cos.c\
       max.c\
       max3.c\
       median.c\
       min.c\
       min3.c\
       module.c\
       nb_digit.c\
       power.c\
       res_0_deg.c\
       res_1_deg.c\
       res_2_deg.c\
       root.c\
       sin.c\
       square.c\
       tan.c

OBJ = $(SRCS:.c=.o)

INC = includes/

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ) :
	$(CC) $(CF) -c $(SRCS) -I $(INC)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
