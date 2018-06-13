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
GIT 		= https://github.com/ptruffault/minishell.git

FLAG		= -Wall -Wextra -Werror

FILES		= builtins.c \
		check_builtin.c \
		check_cmd.c \
		main.c \
		parse_input.c \
		tenvv_tools_2.c \
		tenvv_tools.c \
		tools.c

FILE_FOLDER	= ./srcs/
OBJ_FOLDER 	= ./bin/
SRC			= $(addprefix $(FILE_FOLDER), $(FILES)) 
OBJ			= $(addprefix $(OBJ_FOLDER), $(FILES:.c=.o))

COLOR		= \033[01;34m
NO_COLOR	= \033[00m
OP_COLOR	= \033[1;31m
DONE 		= $(NO_COLOR)[\033[1;32mOK$(NO_COLOR)]

all: bin $(NAME)

$(NAME): $(OBJ)
	@make -C libft all
	@echo "$(OP_COLOR) building $(NAME)$(NO_COLOR)"
	@gcc $(OBJ) -I includes/ -Llibft -lft -o $(NAME)
	@echo "$(DONE)"

bin:
	@mkdir $@

bin/%.o: srcs/%.c 
	@gcc $(FLAG) -I includes/ -c $< -o $@
	@echo "$(COLOR)$< : $(DONE)"

bin/%.o: srcs/tools/%.c
	@gcc $(FLAG) -I includes/ -c $< -o $@		
	@echo "$(COLOR)$< : $(DONE)"

clear:
	@clear

clean:
	@rm -rf $(OBJ) $(OBJ_FOLDER)$(NAME).a
	@rm -rf $(NAME)

fclean: clean
	@make -C libft fclean

re: clear clean all

exe: re
	./$(NAME)

chmod:
	@chmod 777 * $(SRC) includes/$(NAME).h 
	@make -C ./libft chmod

save: clear fclean
	@git add * srcs/* includes/*
	@git commit -m  "make save"
	@git push
	@echo "$(DONE)"

load:
	@rm -rf *
	@echo "$(COLOR)download $(NAME) from github$(NO_COLOR)"
	@git clone $(GIT) TMP && mv TMP/* . && rm -rf TMP libft
	@echo "$(COLOR)download libft from github$(NO_COLOR)"
	@git clone https://github.com/ptruffault/libft.git
