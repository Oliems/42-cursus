# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 13:54:25 by mbarberi          #+#    #+#              #
#    Updated: 2023/01/03 15:26:46 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libftprintf.a

LIBFT_PROJECT	:= libft
LIBFT_MAKE		:= Makefile
LIBFT_PATH		:= ${LIBFT_PROJECT}/libft.a

SRCS			:= ft_printf.c
OBJS			:= $(SRCS:.c=.o)
INCLUDES		:= ft_printf.h

CC				:= gcc
RM				:= rm -f
CFLAGS			:= -Wall -Wextra -Werror -I${LIBFT_PROJECT}

all: $(NAME)

%.o: %.c Makefile $(INCLUDES)
			${CC} ${CFLAGS} -c $<

$(NAME): $(OBJS) ${LIBFT_PROJECT}
			ar -rcs $(NAME) $(OBJS)

${LIBFT_PROJECT}:
			make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} bonus
			cp ${LIBFT_PATH} ${NAME}

clean:
			$(RM) $(OBJS)
			make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} clean

fclean: clean
			$(RM) $(NAME)
			make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} fclean

re: fclean all

.PHONY:	all clean fclean re ${LIBFT_PROJECT}

