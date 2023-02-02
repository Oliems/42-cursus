# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 21:40:52 by mbarberi          #+#    #+#              #
#    Updated: 2023/02/02 13:50:08 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Edit the $(NAME) and $(SRCS) variables as necessary.
SERVER		:=	server
CLIENT		:=	client

SRCS_SE		:=	server.c
SRCS_CL		:=	client.c
SRCS_UT		:=	utils_0.c utils_1.c

CC			:=	gcc
RM			:=	rm

CFLAGS		:=	-Wall -Wextra -Werror
LDFLAGS		:=	-Wall
RMFLAGS		:=	-f

SRCDIR		:=	src
OBJDIR		:=	obj
INCDIR		:=	inc

# Edit the $(HEADERS) variable as necessary.
HEADERS		:=	$(INCDIR)/minitalk.h

LINK.o		:=	$(CC) $(LDFLAGS)
COMPILE.c	:=	$(CC) -I$(INCDIR) $(CFLAGS) -c
REMOVE		:=	$(RM) $(RMFLAGS)

SRCS_SE		+=	$(SRCS_UT)
SRCS_CL		+=	$(SRCS_UT)

SOURCES_SE	:=	$(addprefix $(SRCDIR)/, $(SRCS_SE))
SOURCES_CL	:=	$(addprefix $(SRCDIR)/, $(SRCS_CL))

OBJECTS_SE	:=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES_SE))
OBJECTS_CL	:=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES_CL))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

all: $(SERVER) $(CLIENT)

$(OBJECTS_SE): $(HEADERS) Makefile
$(OBJECTS_CL): $(HEADERS) Makefile

$(SERVER): $(OBJECTS_SE)
	$(LINK.o) -o $(SERVER) $^

$(CLIENT): $(OBJECTS_CL)
	$(LINK.o) -o $(CLIENT) $^

clean:
	$(REMOVE) $(OBJECTS_SE) $(OBJECTS_CL)

fclean: clean
	$(REMOVE) $(SERVER) $(CLIENT)

re: fclean all

.PHONY:	all clean fclean re
