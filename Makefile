# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 14:42:17 by jileroux          #+#    #+#              #
#    Updated: 2023/01/21 18:49:52 by jileroux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################################################################
## ARGUMENTS

NAME	=	so_long
CFLAGS	=	-Wall -Werror -Wextra -g3
CC		=	clang
MLX		=	./mlx
MLX_LIB = 	./mlx/libmlx_Linux.a

#####################################################################
## SOURCES

SRC_FILES = src/main.c\
			src/list.c\
			src/free.c\
			src/path.c\
			src/move.c\
			src/close.c\
			src/ft_itoa.c\
			src/parsing.c\
			src/parsing_2.c\
			src/get_next_line.c\
			src/so_long_utils.c\
			src/get_next_line_utils.c

#####################################################################
## RULES

all: ${NAME}

${NAME}: ${SRC_FILES} $(MLX_LIB)
		${CC} ${CFLAGS} ${SRC_FILES} -o ${NAME} ${MLX_LIB}\
		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(MLX_LIB):
		make -C ${MLX} -j

%.o: %.c
		${CC} ${CFLAGS} -I${MLX} $< -o $@

clean:
		rm -rf *.o

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
