# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 15:27:53 by rriyas            #+#    #+#              #
#    Updated: 2022/06/16 19:22:43 by rriyas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= gcc
RM		= rm -f
SRCS	= sort_small.c sort_extra_large.c chunk.c push_swap.c  parse.c stack.c push_swap_utils.c push_swap_utils2.c sort_large.c split.c
OBJS	= ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror

$(NAME): ${OBJS}
		@${CC} ${CFLAGS} $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
		@${RM} ${OBJS}

fclean:	clean
		@${RM} push_swap

re:		fclean all

.PHONY: all clean fclean re
