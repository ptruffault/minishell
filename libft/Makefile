NAME = libft.a

SRC = ./ft_memset.c \
	  ./ft_strncut.c \
	  ./ft_caps_lock.c \
	  ./ft_bzero.c \
	  ./ft_memcpy.c \
	  ./ft_memmove.c \
	  ./ft_memccpy.c \
	  ./ft_strchr.c \
	  ./ft_memchr.c \
	  ./ft_memcmp.c \
	  ./ft_strcpy.c \
	  ./ft_strdup.c \
	  ./ft_strlen.c \
	  ./ft_strncpy.c \
	  ./ft_strcat.c \
	  ./ft_strncat.c \
	  ./ft_strlcat.c \
	  ./ft_strrchr.c \
	  ./ft_strstr.c \
	  ./ft_strnstr.c \
	  ./ft_strcmp.c \
	  ./ft_strncmp.c \
	  ./ft_atoi.c \
	  ./ft_ismin.c \
	  ./ft_ismaj.c \
	  ./ft_isalpha.c \
	  ./ft_isdigit.c \
	  ./ft_isalnum.c \
	  ./ft_isascii.c \
	  ./ft_isprint.c \
	  ./ft_toupper.c \
	  ./ft_tolower.c \
	  ./ft_memalloc.c \
	  ./ft_itoa.c \
	  ./ft_memdel.c \
	  ./ft_putchar_fd.c \
	  ./ft_putchar.c \
	  ./ft_putendl_fd.c \
	  ./ft_putendl.c \
	  ./ft_putnbr_fd.c \
	  ./ft_putnbr.c \
	  ./ft_putstr_fd.c \
	  ./ft_putstr.c \
	  ./ft_putstr_tab.c \
	  ./ft_strclr.c \
	  ./ft_strdel.c \
	  ./ft_strequ.c \
	  ./ft_striter.c \
	  ./ft_striteri.c \
	  ./ft_strjoin.c \
	  ./ft_strmap.c \
	  ./ft_strmapi.c \
	  ./ft_strnequ.c \
	  ./ft_strnew.c \
	  ./ft_strsplit.c \
	  ./ft_strsub.c \
	  ./ft_strtrim.c \
	  ./ft_lstnew.c \
	  ./ft_lstdelone.c \
	  ./ft_lstdel.c \
	  ./ft_lstadd.c \
	  ./ft_lstiter.c \
	  ./ft_lstmap.c \
	  ./ft_sqrt.c \
	  ./ft_realloc.c \
	  ./ft_get_input.c \
	  ./ft_new_path.c \
	  ./ft_get_tfile.c \
	  ./ft_get_file_information.c 	\
	  ./ft_free_tfile.c \
	  ./ft_new_tfile.c \
	  ./ft_dir_compltion.c \
	  ./ft_search_tfile.c \
	  ./ft_get_prev_path.c \
	  ./ft_putstr_color_fd.c \
	  ./ft_sort_tfile.c \
	  ./ft_put_tfile.c

OBJ = $(SRC:.c=.o)

RM = rm -f

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(SRC) -I .
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all