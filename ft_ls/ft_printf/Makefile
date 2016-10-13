# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/29 11:58:36 by qstemper          #+#    #+#              #
#    Updated: 2016/10/13 09:41:21 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CF = -Wall -Werror -Wextra

INC = headers

SRCS =	new_buff.c\
		exp_buff.c\
		del_buff.c\
		add_darray.c\
		del_darray.c\
		dump_darray.c\
		dump_i_darray.c\
		new_darray.c\
		add_darray2.c\
		del_darray2.c\
		dump_darray2.c\
		new_darray2.c\
		dlist_add_in.c\
		dlist_add_ip.c\
		dlist_add_n.c\
		dlist_add_p.c\
		dlist_del.c\
		dlist_delone.c\
		dlist_map.c\
		dlist_new.c\
		wide_c_len.c\
		wide_ctoa.c\
		ft_printf.c\
		ft_printf_color.c\
		ft_printf_diouxpcs_val.c\
		ft_printf_family.c\
		ft_printf_finaly.c\
		ft_printf_flush.c\
		ft_printf_get_arg.c\
		ft_printf_get_index.c\
		ft_printf_init.c\
		ft_printf_save.c\
		ft_printf_set.c\
		ft_printf_set1.c\
		ft_printf_set2.c\
		ft_printf_set3.c\
		ft_printf_special_char.c\
		ft_printf_special_number1.c\
		ft_printf_special_number2.c\
		ft_printf_static.c\
		ft_printf_tools.c\
		ft_printf_vfamily.c

SRCS_LIBFT =	libft/ft_memset.c\
				libft/ft_bzero.c\
				libft/ft_memcpy.c\
				libft/ft_memccpy.c\
				libft/ft_memmove.c\
				libft/ft_memchr.c\
				libft/ft_memalloc.c\
				libft/ft_memdel.c\
				libft/ft_memcmp.c\
				libft/ft_isalpha.c\
				libft/ft_isdigit.c\
				libft/ft_isalnum.c\
				libft/ft_isascii.c\
				libft/ft_isprint.c\
				libft/ft_isblank.c\
				libft/ft_toupper.c\
				libft/ft_tolower.c\
				libft/ft_strlen.c\
				libft/ft_strdup.c\
				libft/ft_strndup.c\
				libft/ft_strcpy.c\
				libft/ft_strncpy.c\
				libft/ft_strcat.c\
				libft/ft_strlcat.c\
				libft/ft_strchr.c\
				libft/ft_strrchr.c\
				libft/ft_strstr.c\
				libft/ft_strnstr.c\
				libft/ft_strcmp.c\
				libft/ft_strncmp.c\
				libft/ft_atoi.c\
				libft/ft_strnew.c\
				libft/ft_strdel.c\
				libft/ft_strclr.c\
				libft/ft_striter.c\
				libft/ft_striteri.c\
				libft/ft_strmap.c\
				libft/ft_strmapi.c\
				libft/ft_strequ.c\
				libft/ft_strnequ.c\
				libft/ft_strsub.c\
				libft/ft_strjoin.c\
				libft/ft_strtrim.c\
				libft/ft_strsplit.c\
		 		libft/ft_itoa.c\
				libft/ft_putchar.c\
				libft/ft_putstr.c\
				libft/ft_putendl.c\
				libft/ft_putnbr.c\
				libft/ft_putchar_fd.c\
				libft/ft_putstr_fd.c\
				libft/ft_putendl_fd.c\
				libft/ft_putnbr_fd.c\
				libft/ft_lstnew.c\
				libft/ft_lstdelone.c\
				libft/ft_lstdel.c\
				libft/ft_lstadd.c\
				libft/ft_lstiter.c\
				libft/ft_lstmap.c\
				libft/ft_lstaddback.c

OBJ = $(SRCS:.c=.o)

OBJ_LIBFT = $(SRCS_LIBFT:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ_LIBFT)
	@ar cr $(NAME) $(OBJ) $(OBJ_LIBFT)
	@ranlib $(NAME)

%.o:%.c
	@$(CC) $(CF) -o $@ -c $< -I $(INC)

clean :
	@rm -rf $(OBJ) $(OBJ_LIBFT)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
