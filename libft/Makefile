# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 17:06:24 by mbarberi          #+#    #+#              #
#    Updated: 2023/01/23 22:06:08 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Edit the $(NAME) and $(SRCS) variables as necessary.
NAME		:=	libft.a

SRCS		:=	ft_atoi.c \
				ft_isalpha.c \
				ft_itoa.c \
				ft_memcpy.c \
				ft_putendl_fd.c \
				ft_strchr.c \
				ft_strlcpy.c \
				ft_strnstr.c \
				ft_tolower.c \
				ft_bzero.c \
				ft_isascii.c \
				ft_memmove.c \
				ft_putnbr_fd.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_strrchr.c \
				ft_toupper.c \
				ft_calloc.c \
				ft_isdigit.c \
				ft_memchr.c \
				ft_memset.c \
				ft_putstr_fd.c \
				ft_strjoin.c \
				ft_strmapi.c \
				ft_strtrim.c \
				ft_isalnum.c \
				ft_isprint.c \
				ft_memcmp.c \
				ft_putchar_fd.c \
				ft_split.c \
				ft_strlcat.c \
				ft_strncmp.c \
				ft_striteri.c \
				ft_substr.c \
				ft_abs.c \
				ft_islower.c \
				ft_isspace.c \
				ft_isupper.c \
				ft_ndigit.c \
				ft_permute_char.c \
				ft_permute_int.c \
				get_next_line.c \
				ft_itoa_base.c \
				ft_reverse.c

SRCSBONUS	:= 	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

CC			:=	gcc
RM			:=	rm

CFLAGS		:=	-Wall -Wextra -Werror
LDFLAGS		:=	-Wall
RMFLAGS		:=	-f

SRCDIR		:=	src
OBJDIR		:=	obj
INCDIR		:=	inc

# Edit the $(HEADERS) variable as necessary.
HEADERS		:=	$(INCDIR)/libft.h

LINK.o		:=	$(CC) $(LDFLAGS)
COMPILE.c	:=	$(CC) -I$(INCDIR) $(CFLAGS) -c
REMOVE		:=	$(RM) $(RMFLAGS)

SOURCES				:=	$(addprefix $(SRCDIR)/, $(SRCS))
SOURCES_BONUS		:=	$(addprefix $(SRCDIR)/, $(SRCSBONUS))
OBJECTS				:=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
OBJECTS_BONUS		:=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES_BONUS))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

all: $(NAME)

$(OBJECTS): $(HEADERS) Makefile
$(OBJECTS_BONUS): $(HEADERS) Makefile

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $^

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	ar -rcs $(NAME) $^

clean:
	$(REMOVE) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY:	all bonus clean fclean re
