# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 20:06:31 by jkarosas          #+#    #+#              #
#    Updated: 2022/03/10 20:32:06 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRC			=	src/so_long.c \
				src/event.c \
				src/end_game.c \
				src/map_check.c \
				src/map_get.c \
				src/map_init.c \
				src/map_read.c \
				src/move_count.c \
				src/render.c \
				src/xpm_init.c \

OBJ            = ${SRC:.c=.o}

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
LFLAGS		=	-L libft -L mlx -L ft_printf
MLX_FLAGS	= 	-lm -lmlx -lXext -lX11
INC			=	-I ./includes -I ./libft -I ./mlx -I ./ft_printf
LIB			=	libft/libft.a ft_printf/libftprintf.a


all:		${NAME}

${NAME}:	${OBJ}
			make -s -C libft
			make -s -C mlx
			make -s -C ft_printf
			${CC} ${FLAGS} ${LFLAGS} ${OBJ} -o ${NAME} ${LIB} -lft ${MLX_FLAGS}

.c.o:
			${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

clean:
			make clean -s -C libft
			make clean -s -C mlx
			make clean -s -C ft_printf
			rm -rf ${OBJ}

fclean:		clean
			make fclean -s -C libft
			make fclean -s -C ft_printf
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re