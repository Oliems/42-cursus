# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 13:54:25 by mbarberi          #+#    #+#              #
#    Updated: 2023/01/05 14:57:22 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libftprintf.a
CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror
RM				:= rm -f

SRCS			:= ft_printf.c ft_printf_utils.c
OBJS			:= $(SRCS:.c=.o)
INCLUDES		:= ft_printf.h

all: $(NAME)

%.o: %.c Makefile $(INCLUDES)
	${CC} ${CFLAGS} -c $<

$(NAME): $(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
