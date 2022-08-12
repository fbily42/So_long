# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbily <fbily@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 19:58:02 by fbily             #+#    #+#              #
#    Updated: 2022/08/12 03:32:24 by fbily            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c parsing.c parsing_2.c mlx_utils.c mlx_utils_2.c draw.c draw_2.c cleanning.c

SRCS = $(addprefix ${SRC_PATH}, ${SRC})

SRC_PATH = ./srcs/

OBJ = ${SRCS:.c=.o}

INC = -I./includes

LIB = -L./Libs/ -lft -L./Libs/ -lprintf -L./Libs/ -lmlx -lXext -lX11 -lm -lz

CC = gcc

CFLAGS = -Wall -Wextra -Werror

####### COLORS #######

GREEN = "\033[92m"
CYAN = "\033[96m"
BOLD = "\033[1m"
NC = "\033[0m"
# NC = No Colors (use for reset)

all : ${NAME}

${NAME} : ${OBJ}
	make --no-print-directory header
	@make --no-print-directory -C Libs/Libft
	@make --no-print-directory -C Libs/ft_printf
	@make --no-print-directory -C Libs/mlx_linux
	@cp ./Libs/Libft/libft.a Libs
	@cp ./Libs/ft_printf/libprintf.a Libs
	@cp ./Libs/mlx_linux/libmlx.a Libs
	@${CC} ${CFLAGS} ${INC} -o ${NAME} ${OBJ} ${LIB}
	@echo ${CYAN}${BOLD}Compilation ${NC}[${GREEN}OK${NC}]

# Lancer avec "make CFLAGS+=-g3" pour debug.

%.o : %.c
	@${CC} ${CFLAGS} ${INC} -o $@ -c $<
		
clean :
	@make $@ --no-print-directory -C Libs/Libft
	@make $@ --no-print-directory -C Libs/ft_printf
	@rm -f ${OBJ}

fclean : clean
	@make $@ --no-print-directory -C Libs/Libft
	@make $@ --no-print-directory -C Libs/ft_printf
	@make --no-print-directory clean Libs/mlx_linux
	@rm -f Libs/libft.a Libs/libprintf.a Libs/libmlx.a
	@rm -f ${NAME}
	@echo ${CYAN}${BOLD}Cleanning ${NC}[${GREEN}OK${NC}]
	
re : fclean all

define HEADER
\033[92m
	███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗         ██╗    ███████╗██████╗ ██╗██╗  ██╗   ██╗
	██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝        ██╔╝    ██╔════╝██╔══██╗██║██║  ╚██╗ ██╔╝
	███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗      ██╔╝     █████╗  ██████╔╝██║██║   ╚████╔╝ 
	╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║     ██╔╝      ██╔══╝  ██╔══██╗██║██║    ╚██╔╝  
	███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝    ██╔╝       ██║     ██████╔╝██║███████╗██║   
	╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝     ╚═╝        ╚═╝     ╚═════╝ ╚═╝╚══════╝╚═╝   
\033[0m                                                                                                           
endef
export HEADER

header :
	clear
	@echo "$$HEADER"

.PHONY : all clean fclean re