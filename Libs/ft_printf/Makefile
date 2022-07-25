# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbily <fbily@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 15:41:02 by fbily             #+#    #+#              #
#    Updated: 2022/07/25 21:21:40 by fbily            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

SRC = ft_printf.c ft_print_hexa.c ft_print_int.c ft_print_ptr.c ft_print_string.c

SRC_PATH = ./srcs/

SRCS = $(addprefix ${SRC_PATH}, ${SRC})

OBJ = ${SRCS:.c=.o}

INC = -I./includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJ}
	ar rc ${NAME} $^

%.o : %.c
	${CC} ${CFLAGS} ${INC} -o $@ -c $<

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}
	
re : fclean all

.PHONY: all clean fclean re