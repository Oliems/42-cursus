# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 21:40:52 by mbarberi          #+#    #+#              #
#    Updated: 2023/03/23 15:20:50 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# If necessary we can use $(info VARIABLE:$(VARIABLE)) to debug.
# We can also use make -d.

# Edit the $(NAME) and $(SRCS) variables as necessary.
NAME		:=	philo
SRCS		:=	main.c \
				philo_helpers.c \
				philo_init.c \
				philo_thread.c

CC			:=	cc
RM			:=	rm

SRCDIR		:=	src
OBJDIR		:=	obj
INCDIR		:=	inc

INCFLAGS	:= -I$(INCDIR)
LIBFLAGS	:= -lpthread
DEBUGFLAGS	:= -g3 -fsanitize=address -fno-omit-frame-pointer -Wno-format-security
CFLAGS		:=	-Wall -Wextra # -Werror
LDFLAGS		:=	$(CFLAGS)
RMFLAGS		:=	-f

# Edit the $(HEADERS) variable as necessary.
HEADERS		:=	$(INCDIR)/philo.h
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
	$(CC) $(OBJECTS) $(INCFLAGS) $(LIBFLAGS) -o $(NAME)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
