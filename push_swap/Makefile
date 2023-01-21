# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 13:07:50 by mbarberi          #+#    #+#              #
#    Updated: 2023/01/16 18:47:05 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
RM			:=	rm -f

INCDIR		:=	inc
SRCDIR		:=	src/push_swap
OBJDIR		:=	obj

SRC			:=	action.c \
				check.c \
				list_utils.c \
				main.c \
				push_swap_utils.c \
				setup.c \
				solve.c

OBJS		:=	$(OBJDIR)/action.o \
				$(OBJDIR)/check.o \
				$(OBJDIR)/list_utils.o \
				$(OBJDIR)/main.o \
				$(OBJDIR)/push_swap_utils.o \
				$(OBJDIR)/setup.o \
				$(OBJDIR)/solve.o

OBJ := $($(SRCDIR)/$(SRC):%.c=$(OBJDIR)/%.o)

$(info $(OBJ))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	${CC} -o ${NAME} ${OBJS}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
