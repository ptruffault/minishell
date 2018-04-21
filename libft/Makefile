NAME = libft.a
			
GIT 		= https://github.com/ptruffault/libft.git

SRC0 = ./ft_memset.c ./ft_strncut.c ./ft_caps_lock.c ./ft_bzero.c
SRC1 = ./ft_memcpy.c ./ft_memmove.c ./ft_memccpy.c ./ft_strchr.c 
SRC2 = ./ft_memchr.c ./ft_memcmp.c  ./ft_strcpy.c ./ft_strdup.c 
SRC3 =	./ft_strlen.c ./ft_strncpy.c ./ft_strcat.c ./ft_strncat.c 
SRC4 =	./ft_strlcat.c ./ft_strrchr.c ./ft_strstr.c  ./ft_strnstr.c 
SRC5 =	./ft_strcmp.c  ./ft_strncmp.c ./ft_atoi.c ./ft_ismin.c 
SRC6 =	./ft_ismaj.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c 
SRC7 =	./ft_isascii.c ./ft_isprint.c ./ft_toupper.c ./ft_tolower.c 
SRC8 =	./ft_memalloc.c ./ft_itoa.c ./ft_memdel.c ./ft_putchar_fd.c 
SRC9 = 	./ft_putchar.c ./ft_putendl_fd.c ./ft_putendl.c ./ft_putnbr_fd.c 
SRC10 =	./ft_putnbr.c ./ft_putstr_fd.c ./ft_putstr.c ./ft_putstr_tab.c 
SRC11 = ./ft_strclr.c ./ft_strdel.c ./ft_strequ.c ./ft_striter.c 
SRC12 =	./ft_striteri.c ./ft_strjoin.c ./ft_strmap.c ./ft_strmapi.c 
SRC13 =	./ft_strnequ.c ./ft_strnew.c ./ft_strsplit.c ./ft_strsub.c 
SRC14 =	./ft_strtrim.c ./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c 
SRC15 =	./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_sqrt.c ./get_next_line.c
SRC16 =	./ft_realloc.c ./ft_get_input.c ./ft_new_path.c ./ft_get_tfile.c 
SRC17 =	./ft_get_file_information.c ./ft_free_tfile.c ./ft_new_tfile.c 
SRC18 =	./ft_dir_compltion.c ./ft_search_tfile.c ./ft_get_prev_path.c ./ft_strpull.c 
SRC19 =	./ft_putstr_color_fd.c ./ft_sort_tfile.c ./ft_put_tfile.c ./ft_freestrarr.c 
SRC20 =	./ft_str_startwith.c ./ft_strsplit_word.c ./ft_strncpy.c ./ft_strndup.c \

OBJ = $(SRC1:.c=.o) $(SRC2:.c=.o) $(SRC3:.c=.o) $(SRC4:.c=.o) $(SRC5:.c=.o) $(SRC6:.c=.o) \
 $(SRC7:.c=.o) $(SRC8:.c=.o) $(SRC9:.c=.o) $(SRC10:.c=.o) $(SRC11:.c=.o) $(SRC12:.c=.o) \
 $(SRC13:.c=.o) $(SRC14:.c=.o) $(SRC15:.c=.o) $(SRC16:.c=.o) $(SRC17:.c=.o) $(SRC18:.c=.o) \
 $(SRC19:.c=.o) $(SRC20:.c=.o) $(SRC0:.c=.o)

RM = rm -f

FLAG = -Wall -Werror -Wextra

COULEUR		= \033[01;34m

SUCESS		= \033[00m[\033[1;32mOK\033[00m]

LOADING  = \033[00;31m%\033[00m

all: $(NAME)

$(NAME):
	@echo "$(COULEUR)\t+ build with gcc -c $(FLAG) (libft/*.c) -I .\033[00m"
	@gcc -c $(FLAG) $(SRC20) -I .
	@gcc -c $(FLAG) $(SRC19) -I .
	@echo -n "\t$(LOADING)" 
	@gcc -c $(FLAG) $(SRC18) -I .
	@echo -n " $(LOADING)" 
	@gcc -c $(FLAG) $(SRC17) -I .
	@echo -n " $(LOADING)" 
	@gcc -c $(FLAG) $(SRC16) -I .
	@echo -n " $(LOADING)" 
	@gcc -c $(FLAG) $(SRC15) -I .
	@echo -n " $(LOADING)"  
	@gcc -c $(FLAG) $(SRC14) -I .
	@echo -n " $(LOADING)"  
	@gcc -c $(FLAG) $(SRC13) -I .
	@echo -n " $(LOADING)" 
	@gcc -c $(FLAG) $(SRC12) -I .
	@echo -n " $(LOADING)"  
	@gcc -c $(FLAG) $(SRC11) -I .
	@echo -n " $(LOADING)" 
	@gcc -c $(FLAG) $(SRC10) -I .
	@echo -n " $(LOADING)"  
	@gcc -c $(FLAG) $(SRC9) -I .
	@echo -n " $(LOADING)"  
	@gcc -c $(FLAG) $(SRC8) -I .
	@echo -n " $(LOADING)" 
	@gcc -c $(FLAG) $(SRC7) -I .
	@echo -n " $(LOADING)" 
	@gcc -c $(FLAG) $(SRC6) -I .
	@echo -n " $(LOADING)"
	@echo -n " $(LOADING)"  
	@gcc -c $(FLAG) $(SRC5) -I .
	@echo -n " $(LOADING)" 
	@echo -n " $(LOADING)" 
	@echo -n " $(LOADING)"
	@gcc -c $(FLAG) $(SRC4) -I .
	@echo -n " $(LOADING)" 
	@echo -n " $(LOADING)" 
	@gcc -c $(FLAG) $(SRC3) -I .
	@echo -n " $(LOADING)" 
	@echo -n " $(LOADING)"
	@echo -n " $(LOADING)" 
	@gcc -c $(FLAG) $(SRC2) -I .
	@echo -n " $(LOADING)" 
	@echo -n " $(LOADING)" 
	@echo -n " $(LOADING)"
	@echo -n " $(LOADING)"  
	@gcc -c $(FLAG) $(SRC1) -I .
	@echo -n " $(LOADING)" 
	@echo -n " $(LOADING)" 
	@gcc -c $(FLAG) $(SRC0) -I .
	@echo " $(LOADING)" 
	@echo "\t$(SUCESS)"
	@echo "$(COULEUR)\t+ ar rc && ranlib libft\033[00m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\t$(SUCESS)"

last:
	@echo "$(COULEUR)\t+ recompile only :\033[00m"
	@echo "$(COULEUR)\t+ $(SRC20) \033[00m"
	@rm -rf SRC20:.c=.o libft.a
	@gcc -c $(FLAG) $(SRC20) -I .
	@echo "\t$(SUCESS)"
	@echo "$(COULEUR)\t+ create libft.a\033[00m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\t$(SUCESS)"

clean:
	@echo "$(COULEUR)\t+ Cleaning (libft/*.o)\033[00m"
	@$(RM) $(OBJ)
	@echo "\t$(SUCESS)"

fclean: clean
	@echo "$(COULEUR)\t+ Cleaning (libft/libft.a)\033[00m"
	@$(RM) $(NAME)
	@echo "\t$(SUCESS)"

save: clean fclean
	@git add *
	@git commit -m "make save"
	@git push
	@echo "$(SUCESS)"

load: clear fclean
	@echo "$(COULEUR)\t+ removing all file\033[00m"
	rm -rf *
	@echo "\t$(SUCESS)"
	@echo "$(COULEUR)\t+ download libft\033[00m"
	@git clone $(GIT) git_tmp
	@cp git_tmp/* .
	@rm git_tmp
	@echo "$(SUCESS)"

re: fclean all