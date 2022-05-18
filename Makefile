# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louis <louis@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 15:26:27 by louis             #+#    #+#              #
#    Updated: 2022/03/02 16:20:03 by jlaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_memcpy.c colors.c julia.c hooks.c ft_strcmp.c\
		mandelbrot.c burning_ship.c menu.c zoom.c

OBJS	= ${SRCS:.c=.o}

GCC		= gcc -Wall -Werror -Wextra -I./mlx -Lmlx -lmlx

PRINTF	= ./ft_printf/libftprintf.a

FW		= -framework OpenGl -framework AppKit

RM		= rm -f

NAME	= fractol

all:		${NAME}

${NAME}:	${OBJS}
					${GCC} ${FW} ${PRINTF} -I. -I./ft_printf -o ${NAME} ${OBJS}

clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
