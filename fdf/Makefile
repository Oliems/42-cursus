# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 21:40:52 by mbarberi          #+#    #+#              #
#    Updated: 2023/03/23 15:00:45 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# If necessary we can use $(info VARIABLE:$(VARIABLE)) to debug.
# We can also use make -d.

# Edit the $(NAME) and $(SRCS) variables as necessary.
NAME		:=	fdf
SRCS		:=	fdf_init.c \
				main.c \
				map_checking.c \
				map_checking_helpers.c \
				map_draw.c \
				map_parsing.c \
				map_parsing_helpers.c \
				misc_helpers.c \
				mlx_helpers.c

CC			:=	gcc
RM			:=	rm

SRCDIR		:=	src
OBJDIR		:=	obj
INCDIR		:=	inc
SYSINC		:=	/usr/include
SYSLIB		:=	/usr/lib
MLXDIR		:=	../_submodules/minilibx-linux
LFTDIR		:=	../_submodules/mlc

INCFLAGS	:= -I$(INCDIR) -I$(SYSINC) -I$(MLXDIR) -I$(LFTDIR)/inc
LIBFLAGS	:= -L$(MLXDIR) -L$(LFTDIR) -L$(SYSLIB) -lmlx_Linux -lft -lXext -lX11 -lm
CFLAGS		:=	-Wall -Wextra -Werror -O3 -Ofast -march=native -ffast-math $(INCFLAGS)
LDFLAGS		:=	$(CFLAGS)
RMFLAGS		:=	-f

# Edit the $(HEADERS) variable as necessary.
HEADERS		:=	$(INCDIR)/fdf.h

LINK.o		:=	$(CC) $(LDFLAGS)
COMPILE.c	:=	$(CC) $(CFLAGS) -c
REMOVE		:=	$(RM) $(RMFLAGS)

SOURCES		:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJECTS		:=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

all: libft mlx $(NAME)

$(OBJECTS): $(HEADERS) Makefile

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(INCFLAGS) $(LIBFLAGS) -o $(NAME)

libft:
	make -C $(LFTDIR)

mlx:
	make -C $(MLXDIR)

clean:
	rm -rf obj/
	make -C $(MLXDIR) clean
	make -C $(LFTDIR) clean

fclean: clean
	$(REMOVE) $(NAME)
	make -C $(LFTDIR) fclean

re: fclean all

.PHONY:	all clean fclean re libft mlx
