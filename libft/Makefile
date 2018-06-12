NAME		=	libft.a

GIT 		= https://github.com/ptruffault/libft.git

FILES = ft_memset.c ft_strncut.c ft_bzero.c ft_strnew_nchar.c \
ft_memcpy.c ft_memmove.c ft_memccpy.c ft_strchr.c \
ft_memchr.c ft_memcmp.c  ft_strcpy.c ft_strdup.c \
ft_strlen.c ft_strncpy.c ft_strcat.c ft_strncat.c \
ft_strlcat.c ft_strrchr.c ft_strstr.c  ft_strnstr.c \
ft_strcmp.c  ft_strncmp.c ft_atoi.c ft_ismin.c \
ft_ismaj.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
ft_memalloc.c ft_itoa.c  ft_putchar_fd.c ft_memdel.c ft_strdel.c\
ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c \
ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_putstr_tab.c \
ft_strclr.c ft_strequ.c ft_striter.c ft_search_tfile.c ft_get_prev_path.c \
ft_striteri.c ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strpull.c \
ft_strnequ.c ft_strnew.c ft_strsplit.c ft_strsub.c ft_get_input.c\
ft_strtrim.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_strsplit_word.c\
ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_sqrt.c ft_strarrlen.c\
ft_realloc.c  ft_new_path.c ft_get_tfile.c ft_error.c ft_strndup.c\
ft_get_file_information.c ft_free_tfile.c ft_new_tfile.c \
ft_putstr_color_fd.c ft_sort_tfile.c ft_freestrarr.c \
ft_str_startwith.c ft_strsplit_whitespace.c ft_char_to_str.c \
ft_itoa_base.c ft_stradd_char.c ft_strjoin_fr.c ft_arr_to_str.c \

FLAG = -Wall -Werror -Wextra

FILE_FOLDER	= ./srcs/
OBJ_FOLDER 	= ./bin/
SRC			= $(addprefix $(FILE_FOLDER), $(FILES)) 
OBJ			= $(addprefix $(OBJ_FOLDER), $(FILES:.c=.o))

COLOR		= \033[01;34m
NO_COLOR	= \033[00m
OP_COLOR	= \033[1;34m
DONE		= $(NO_COLOR)[\033[1;32mOK$(NO_COLOR)]


all:  bin $(NAME)

$(NAME): $(OBJ) 
	@ar rc $@ $^
	@ranlib $@
	@echo "$(OP_COLOR)\tbuilding $(NAME)\t $(DONE)"

bin:
	@mkdir $@

bin/%.o: srcs/%.c 
	@cat $< > $<tmp && rm -rf $< && mv $<tmp $< 
	@gcc $(FLAG) -I includes/ -c $< -o $@
	@echo "\t$(COLOR)$< : $(DONE)"

clean:
	@rm -rf $(OBJ)
	@echo "$(OP_COLOR)Cleaning (libft/*.o)\t $(DONE)"

fclean: clean
	@echo "$(OP_COLOR)Cleaning (libft/libft.a) $(DONE)"
	@rm -rf $(NAME)

chmod:
	@chmod 777 *
	@chmod 777 srcs/*
	@chmod 777 includes/*

save: clean fclean
	@git add * $(SRCS)
	@git commit -m "[make save]"
	@git push
	@echo "\t$(DONE)"

re: fclean all





































