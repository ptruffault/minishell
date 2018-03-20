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

LIB_PATH	= ./libft/

LIB			= -Llibft/ -lft

SRC			= srcs/main.c \
			
CFLAGS		= -Wall -Werror -Wextra

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
	@echo "$(COULEUR) -Cleaning libft and delete $(NAME) \033[00m"
	@make -C $(LIB_PATH) fclean
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

save: clear fclean
	@git add *
	@git commit -m "make save"
	@git push

load: clear fclean
	@rm -rf srcs
	@rm -rf includes
	@rm -rf libft
	@rm -rf auteur
	@git clone https://github.com/ptruffault/ft_ls.git
	@cp -r ft_ls/srcs .
	@cp -r ft_ls/includes .
	@cp -r ft_ls/libft .
	@cp ft_ls/auteur .
	@rm -rf ft_ls
	@echo "$(SUCESS)"

.PHONY: all small_clean clean fclean re fast_re
