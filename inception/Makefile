# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 11:05:34 by mbarberi          #+#    #+#              #
#    Updated: 2023/09/28 12:00:01 by mbarberi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -f = specify the location of the compose file
DOCKER_COMPOSE	:= docker-compose -f srcs/docker-compose.yml
VOLUMES			:= $(HOME)/data/mysql/ $(HOME)/data/wordpress/

# define standard colors
_END			:=	\033[0m
_GREEN			:=	\033[32m

all: up

# -d = run the containers in the background (terminal is still usable while running)
# --build = force to rebuild the images of the services
up: | $(VOLUMES)
	@echo "$(_GREEN) Rebuild and start all the containers in detached mode$(_END)"
	${DOCKER_COMPOSE} up -d --build

debug: | $(VOLUMES)
	@echo "$(_GREEN) Rebuild and start all the containers in attached mode$(_END)"
	${DOCKER_COMPOSE} up --build

build:
	@echo "$(_GREEN)Build images$(_END)"
	$(DOCKER_COMPOSE) build

$(VOLUMES):
	mkdir -p $(VOLUMES)

start:
	@echo "$(_GREEN)Start containers$(_END)"
	$(DOCKER_COMPOSE) start

restart:
	@echo "$(_GREEN)Restart containers$(_END)"
	$(DOCKER_COMPOSE) restart

stop:
	@echo "$(_GREEN)Stop containers$(_END)"
	$(DOCKER_COMPOSE) stop

ls:
	@echo "$(_GREEN)------------------------List running containers-------------------------$(_END)"
	$(DOCKER_COMPOSE) ps
	@echo "$(_GREEN)------------------------------List images-------------------------------$(_END)"
	docker images
	@echo "$(_GREEN)------------------------------List volumes------------------------------$(_END)"
	docker volume ls

# --rmi all = remove all images associated with the services
# --volumes = remove any volume
# --remove-orphans = remove any container unused by docker-compose file
clean:
	@echo "$(_GREEN)Stop and remove containers, volumes and networks$(_END)"
	$(DOCKER_COMPOSE) down --rmi all --volumes --remove-orphans

fclean: clean
	@echo "$(_GREEN)Removes images, containers and volumes$(_END)"
	sudo rm -rf $(VOLUMES)

# -a = remove all objects including unused
# -f = force the removal without confirmation
prune: fclean
	@echo "$(_GREEN)Removes all unused images, containers, networks and volumes$(_END)"
	sudo docker system prune -af

re: prune all

.PHONY: all build up start restart stop ls clean fclean prune re debug
