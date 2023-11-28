# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 13:54:25 by mbarberi          #+#    #+#              #
#    Updated: 2023/01/23 21:53:44 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Edit the $(NAME) and $(SRCS) variables as necessary.
NAME		:=	libftprintf.a
SRCS		:=	ft_printf.c ft_printf_utils.c

CC			:=	gcc
RM			:=	rm

CFLAGS		:=	-Wall -Wextra -Werror
LDFLAGS		:=	-Wall
RMFLAGS		:=	-f

SRCDIR		:=	src
OBJDIR		:=	obj
INCDIR		:=	inc

# Edit the $(HEADERS) variable as necessary.
HEADERS		:=	$(INCDIR)/ft_printf.h

LINK.o		:=	$(CC) $(LDFLAGS)
COMPILE.c	:=	$(CC) -I$(INCDIR) $(CFLAGS) -c
REMOVE		:=	$(RM) $(RMFLAGS)

SOURCES		:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJECTS		:=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

all: $(NAME)

$(OBJECTS): $(HEADERS) Makefile

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $^

clean:
	rm -rf obj/

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
