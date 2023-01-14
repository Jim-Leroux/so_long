# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 14:42:17 by jileroux          #+#    #+#              #
#    Updated: 2023/01/14 16:12:07 by jileroux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################################################################
## ARGUMENTS

NAME = so_long
CFLAGS = -Wall -Werror -Wextra
CC = clang

#####################################################################
## SOURCES

SRC_FILES = src/main.c\
			src/list.c\
			src/parsing.c\
			src/parsing_2.c\
			src/get_next_line.c\
			src/get_next_line_utils.c

#####################################################################
## RULES

all: ${NAME}

${NAME}: ${SRC_FILES}
		${CC} ${CFLAGS} ${SRC_FILES} -g -o ${NAME}

%.o: %.c
		${CC} ${CFLAGS} $< -o $@

clean:
		rm -rf *.o

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
