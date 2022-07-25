# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbily <fbily@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 19:58:02 by fbily             #+#    #+#              #
#    Updated: 2022/07/25 23:20:40 by fbily            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = workshop_mlx.c

SRC_PATH = ./srcs/

SRCS = $(addprefix ${SRC_PATH}, ${SRC})

OBJ = ${SRCS:.c=.o}

INC = -I./includes

LIB = -L./Libs/ -lft -L./Libs/ -lprintf -L./Libs/ -lmlx -lXext -lX11 -lm -lz

CC = gcc

CFLAGS = -Wall -Wextra -Werror

${NAME} : ${OBJ}
	make -C Libs/Libft
	make -C Libs/ft_printf
	make -C Libs/mlx_linux
	cp ./Libs/Libft/libft.a Libs
	cp ./Libs/ft_printf/libprintf.a Libs
	cp ./Libs/mlx_linux/libmlx.a Libs
	${CC} ${CFLAGS} ${INC} -o ${NAME} ${OBJ} ${LIB}

%.o : %.c
	${CC} ${CFLAGS} ${INC} -o $@ -c $<

clean :
	make $@ -C Libs/Libft
	make $@ -C Libs/ft_printf
	rm -f ${OBJ}

fclean : clean
	make $@ -C Libs/Libft
	make $@ -C Libs/ft_printf
	make clean Libs/mlx_linux
	rm -f Libs/libft.a Libs/libprintf.a Libs/libmlx.a
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re