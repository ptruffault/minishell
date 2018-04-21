# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 11:16:13 by ptruffau          #+#    #+#              #
#    Updated: 2018/01/07 16:59:07 by ptruffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

FOLDERS 	= minishell/
			
GIT 		= https://github.com/ptruffault/minishell.git

SRC			= srcs/*.c

CFLAGS		= -Wall -Werror -Wextra

LIB_PATH	= ./libft/

LIB			= -Llibft/ -lft

COULEUR		= \033[01;34m

SUCESS		= [\033[1;32mOK\033[00m]

all: $(NAME)

clear:
	@clear

$(NAME):
	@echo "$(COULEUR) -Creating libft.a \033[00m"
	@make -C $(LIB_PATH) all
	@echo "$(SUCESS)"
	@echo "$(COULEUR) -Creating $(NAME) \033[00m"
	@gcc $(CFLAGS) $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "$(SUCESS)"

small_clean:
	@rm -rf $(NAME)
	@echo "$(COULEUR) -delete $(NAME) \033[00m"

clean:
	@make -C $(LIB_PATH) clean

fclean:
	@echo "$(COULEUR) -Cleaning\033[00m"
	@make -C $(LIB_PATH) fclean
	@echo "$(COULEUR)\t +delete $(NAME) \033[00m"
	@rm -f $(NAME)
	@echo "$(SUCESS)"

re:	clear fclean all

fast_re: clear small_clean
	@echo "$(COULEUR) -Creating $(NAME) \033[00m"
	@gcc $(CFLAGS) $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "$(SUCESS)"


no_flag: clear small_clean
	@echo "$(COULEUR) -Creating $(NAME) \033[00m"
	@gcc $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "$(SUCESS)"

build:
	@rm -rf *
	@git clone https://github.com/ptruffault/libft.git
	@mkdir srcs
	@mkdir includes
	@mkdir user
	@touch user/cmd_logs
	@echo ptruffau > auteur
	@echo "$(SUCESS)"

chmod:
	@echo "$(COULEUR) -giving permission\033[00m"
	@chmod 777 *
	@chmod 777 libft/*
	@chmod 777 srcs/*
	@chmod 777 includes/*
	@echo "$(SUCESS)"

valgrind:fast_re
	@echo "$(COULEUR) -test leaks with valgrind \033[00m"
	@valgrind --tool=memcheck --leak-check=full ./$(NAME)

tmp:
	@make -C $(LIB_PATH) last
	@make fast_re

zam: fast_re
	./$(NAME)

save: clear fclean
	@git add *
	@git commit -m "make save"
	@git push

load: clear fclean
	@rm -rf srcs
	@rm -rf includes
	@rm -rf libft
	@rm -rf auteur
	@git clone $(GIT)
	@cp -r $(FOLDERS)srcs .
	@cp -r $(FOLDERS)includes .
	@cp -r $(FOLDERS)libft .
	@cp $(FOLDERS)auteur .
	@rm -rf $(FOLDERS)
	@echo "$(SUCESS)"

.PHONY: all small_clean clean fclean re fast_re