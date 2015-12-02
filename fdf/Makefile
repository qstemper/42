# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 18:51:43 by qstemper          #+#    #+#              #
#    Updated: 2015/12/02 21:01:36 by qstemper         ###   ########.fr        #
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
		fdf.c

OBJ = $(SRCS:.c=.o)

LIB = libft.a

LIBFT = -lft

LIBFT_DIR = libft






all : $(EXEC)


$(EXEC) : $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $(EXEC) -I $(INCLUDES) -L $(LIBFT_DIR) $(LIBFT) $(OBJ)

$(LIB) :
	make -C $(LIBFT_DIR)

%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean :
	rm -rf $(OBJ)
fclean :
	rm -rf $(NAME)

re : fclean all

mr proper : clean
	rm -Rf EXEC
#.PHONY : all clean fclean re mr proper
