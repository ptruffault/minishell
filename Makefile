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

NAME		=		minishell
GIT 		=		https://github.com/ptruffault/minishell.git

FLAG		=		-Wall -Wextra -Werror

FILES		=		check_cmd.c \
					main.c \
					correct_input.c \
					run_cmd.c
TOOLS			=	tenvv_tools_2.c \
					tenvv_tools.c \
					tools.c 
BUILTINS		=	builtins.c \
					run_builtin.c \
					ft_env.c
FILE_FOLDER		= 	./srcs/
TOOLS_FOLDER	= 	./srcs/tools/
BUILTINS_FOLDER	=	./srcs/builtins/

OBJ_FOLDER 	= 		./bin/
SRC			= 		$(addprefix $(FILE_FOLDER), $(FILES)) \
					$(addprefix $(TOOLS_FOLDER), $(TOOLS)) \
					$(addprefix $(BUILTINS_FOLDER), $(BUILTINS))  	
OBJ			= 		$(addprefix $(OBJ_FOLDER), $(FILES:.c=.o)) \
					$(addprefix $(OBJ_FOLDER), $(TOOLS:.c=.o)) \
					$(addprefix $(OBJ_FOLDER), $(BUILTINS:.c=.o))

COLOR		= \033[01;34m
NO_COLOR	= \033[00m
OP_COLOR	= \033[1;31m
DONE 		= $(NO_COLOR)[\033[1;32mOK$(NO_COLOR)]

all: bin $(NAME)

$(NAME): $(OBJ) Makefile includes/$(NAME).h
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

bin/%.o: srcs/builtins/%.c
	@gcc $(FLAG) -I includes/ -c $< -o $@		
	@echo "$(COLOR)$< : $(DONE)"

clear:
	@clear

clean:
	@rm -rf $(OBJ)
	@make -C ./libft clean	
fclean: clean
	rm -rf $(NAME)
	@make -C ./libft fclean	

re: clear fclean all

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
