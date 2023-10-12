# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbily <fbily@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 15:41:02 by fbily             #+#    #+#              #
#    Updated: 2022/09/20 17:48:57 by fbily            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

SRC = ft_printf.c ft_print_hexa.c ft_print_int.c ft_print_ptr.c ft_print_string.c

SRC_PATH = ./srcs/

SRCS = $(addprefix ${SRC_PATH}, ${SRC})

OBJ = ${SRCS:.c=.o}

INC = ./includes/

DEPS = ${INC}libftprintf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

####### COLORS #######

GREEN = "\033[92m"
CYAN = "\033[96m"
BOLD = "\033[1m"
NC = "\033[0m"
#Reset : NC = No Colors

all : ${NAME}

${NAME} : ${OBJ} ${DEPS}
	@ar rc ${NAME} $^
	@echo ${CYAN}${BOLD}Printf ${NC}[${GREEN}OK${NC}]

%.o : %.c ${DEPS}
	@${CC} ${CFLAGS} -o $@ -c $<

clean :
	@rm -f ${OBJ}

fclean : clean
	@rm -f ${NAME}
	
re : fclean all

.PHONY: all clean fclean re