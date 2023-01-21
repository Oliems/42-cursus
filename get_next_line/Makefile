# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 17:06:24 by mbarberi          #+#    #+#              #
#    Updated: 2022/12/06 18:03:22 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= a.out
CC		:= clang
CFLAGS	:= -Wall -Wextra -Werror -g3
RM		:= rm -f

INCLUDES	:= get_next_line.h
SRCS		:= main.c get_next_line.c get_next_line_utils.c
OBJS 		:= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c Makefile $(INCLUDES)
	${CC} ${CFLAGS} -c $<

$(NAME): $(OBJS)
			${CC} -o ${NAME} ${OBJS}

clean:
			$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
