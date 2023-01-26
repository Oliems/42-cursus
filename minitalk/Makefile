# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 21:40:52 by mbarberi          #+#    #+#              #
#    Updated: 2023/01/23 22:08:14 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Edit the $(NAME) and $(SRCS) variables as necessary.
NAME		:=	template
SRCS		:=	source.c

CC			:=	gcc
RM			:=	rm

CFLAGS		:=	-Wall -Wextra -Werror
LDFLAGS		:=	-Wall
RMFLAGS		:=	-f

SRCDIR		:=	src
OBJDIR		:=	obj
INCDIR		:=	inc

# Edit the $(HEADERS) variable as necessary.
HEADERS		:=	$(INCDIR)/header.h

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
	$(LINK.o) -o $(NAME) $^

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
