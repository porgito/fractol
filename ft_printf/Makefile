# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: porg <porg@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 16:46:56 by porg              #+#    #+#              #
#    Updated: 2021/11/24 15:03:56 by jlaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_fct.c ft_fct2.c ft_itoa.c\
       ft_printf.c

OBJS = ${SRCS:.c=.o}

GCC  = gcc -Wall -Wextra -Werror -c

RM   = rm -f

AR   = ar cr

RLIB = ranlib 

NAME = libftprintf.a

${NAME}:	${OBJS}
						${AR} ${NAME} ${OBJS}
						${RLIB} ${NAME}

all:		${NAME}

clean:
						${RM} ${OBJS}

fclean:		clean
						${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
