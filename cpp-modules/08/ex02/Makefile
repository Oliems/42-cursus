# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 21:40:52 by mbarberi          #+#    #+#              #
#    Updated: 2023/10/30 11:13:13 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# If necessary we can use $(info VARIABLE:$(VARIABLE)) to debug.
# We can also use make -d.

NAME		:=	08
SRCS		:=	main.cpp MutantStack.cpp
HEAD		:=	MutantStack.hpp

CXX			:=	c++
CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror

EXT			:=	.cpp

REMOVE		:=	rm -rf

SRCDIR		:=	src
OBJDIR		:=	obj
INCDIR		:=	inc

SOURCES		:=	$(addprefix $(SRCDIR)/, $(SRCS))
HEADERS		:=	$(addprefix $(INCDIR)/, $(HEAD))
OBJECTS		:=	$(patsubst $(SRCDIR)/%$(EXT), $(OBJDIR)/%.o, $(SOURCES))

$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

all: $(NAME)

$(OBJECTS): $(HEADERS) Makefile

$(NAME): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(NAME)

clean:
	$(REMOVE) $(OBJDIR)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean
	$(MAKE) all

.PHONY:	all clean fclean re
