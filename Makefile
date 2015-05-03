# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 20:27:42 by tdemay            #+#    #+#              #
#    Updated: 2015/05/03 18:47:24 by frcugy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	game_arkanoid

NAMEBASE	=	$(shell basename $(NAME))

CC			=	gcc

FLAGS		=

LIBS		=	-I ~/glfw-3.1.1/include -framework Cocoa -framework OpenGl -framework IOKit -framework CoreVideo

SRCBASE		=	\
				src/main.c \
				src/get_map.c \
				src/aff_brick.c \
				src/aff_ship.c \
				src/hub.c \
				src/hub2.c \
				src/hub3.c \
				src/nombre.c \
				src/life.c

SRCS		=	$(SRCBASE)

OBJS		=	$(SRCBASE:.c=.o)

INSTALL_PATH    ?= ./

GLFW  ?= https://github.com/glfw/glfw.git

clone-git-repo-if-not-exist = @(cd ${INSTALL_PATH} ; [ -d $(2) ] || git clone $(1) $(2))

.SILENT:

all: install-glwf $(NAME)
	echo "\033[38;5;44m✅  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME): $(OBJS) $(NAME).h ./libft/libft.a ./glfw-3.1.1/src/libglfw3.a
	$(CC) $(FLAGS) $(LIBS) -o $(NAME) $(OBJS) ./libft/libft.a ./glfw-3.1.1/src/libglfw3.a
	echo -en "\r\033[38;5;22m✅  MAKE   $(NAMEBASE)\033[0m\033[K"

%.o: %.c $(NAME).h
	$(CC) $(FLAGS) -c $< -o $@

./glfw-3.1.1/src/libglfw3.a:
	cd ./glfw-3.1.1 && cmake .
	make -C glfw-3.1.1/

./libft/libft.a:
	make -C libft/ fclean
	make -C libft/

install-glwf:
	$(call clone-git-repo-if-not-exist,${GLFW},glfw-3.1.1)

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C libft/ fclean
	if [[ `rm $(OBJS) &> /dev/null 2>&1; echo $$?` == "0" ]]; then           \
		echo -en "\r\033[38;5;124m🔘  CLEAN  $(NAMEBASE)\033[0m\033[K";      \
	else                                                                     \
		printf "\r";                                                         \
	fi

fclean: clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C libft/ fclean
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then           \
		echo -en "\r\033[38;5;124m🔘  FCLEAN $(NAMEBASE)\033[0m\033[K";      \
	else                                                                     \
		printf "\r";                                                         \
	fi

re:			fclean all ./libft/libft.a

.PHONY:		fclean clean re
