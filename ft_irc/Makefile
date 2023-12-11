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

NAME		:=	ircserv
SRCS		:=	Client/Client.cpp \
				main.cpp \
				Channel/Channel.cpp \
				Channel/ChannelName.cpp \
				Channel/modeCmd.cpp \
				Server/Join.cpp \
				Server/Quit.cpp \
				Server/Topic.cpp \
				Server/Part.cpp \
				Server/Mode.cpp \
				Server/Pass.cpp \
				Server/Server.cpp \
				Server/Ping.cpp \
				Server/Nick.cpp \
				Server/Kick.cpp \
				Server/Welcome.cpp \
				Server/Bot.cpp \
				Server/User.cpp \
				Server/cleaning.cpp \
				Server/Privmsg.cpp \
				Server/Invite.cpp \
				NetworkManager.cpp \
				utils.cpp

HEAD		:=	def.hpp \
				Channel.hpp \
				ChannelName.hpp \
				NetworkManager.hpp \
				macro.hpp \
				Server.hpp \
				utils.hpp \
				Client.hpp

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
