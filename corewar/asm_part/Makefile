#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2017/04/22 12:17:08 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			asm

SRC =			main.c\
				ft_getopt.c\
				proginfo.c\
				get_next_line.c\
				op.c\
				ft_printf_fmt.c\
				ft_printf_fmt_2.c\
				perror.c\
				asm_dump_switch_opt.c\
				asm_dump_token.c\
				asm_dump_header.c\
				asm_dump_payload.c\
				asm_grammar.c\
				asm_header.c\
				asm_parse.c\
				asm_payload.c\
				asm_payload_argument.c\
				asm_label.c\
				asm_resolve_label.c\
				asm_instruction.c\
				asm_callback.c\
				asm_match_argument.c\
				asm_match_chars_1.c\
				asm_match_chars_2.c\
				asm_encode_argument.c\
				asm_encode_label.c\
				asm_compile.c

SRC_DIR =		srcs/
OBJ_DIR =		obj/

OBJ =			$(SRC:.c=.o)

COR_SRC =		$(addprefix $(SRC_DIR), %.c)

COR_OBJ =		$(addprefix $(OBJ_DIR), %.o)

ABS_OBJ =		$(addprefix $(OBJ_DIR), $(OBJ))

HEADER =		includes

DEPEND =		asm.h

RESSOURCES =	../ressources/

ABS_DEPEND =	$(addprefix $(HEADER)/, $(DEPEND))

LIBFT =			ft

OBJ_LIBFT =		libft.a

LIBFT_DIR =		libft

ABS_OBJ_LIBFT =	$(addprefix $(LIBFT_DIR)/, $(OBJ_LIBFT))

LIBFT_HEADER =	$(addprefix $(LIBFT_DIR)/, $(HEADER))

CC =			gcc

FLAG =			-Wall -Wextra -Werror

all : $(ABS_OBJ_LIBFT) $(NAME)

$(NAME) : $(ABS_OBJ)
	$(CC) $(FLAG) -g -o $@ $^ -L$(LIBFT_DIR) -l$(LIBFT)

$(COR_OBJ) : $(COR_SRC) $(ABS_DEPEND)
	@mkdir -p obj
	$(CC) $(FLAG) -g -o $@ -c $< -I$(HEADER) -I$(RESSOURCES) -I$(LIBFT_HEADER)

$(ABS_OBJ_LIBFT) :
	make -C $(LIBFT_DIR)

lclean :
	make clean -C $(LIBFT_DIR)

lfclean :
	make fclean -C $(LIBFT_DIR)

lre : 
	make re -C $(LIBFT_DIR)

clean : lclean
	rm -rf $(OBJ_DIR)
	rm -f $(ABS_OBJ)

fclean : clean lfclean
	rm -f $(NAME)

re : fclean lre all
