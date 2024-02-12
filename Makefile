NAME = libftprintf.a

SRC_LIB = ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c \
	ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
	ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
	ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
	ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c

SRC_LIBFT = $(addprefix libft/, $(SRC_LIB))

SRC = ft_printf.c ft_print_ptr.c ft_printf_utils.c ft_print_unsigned.c ft_print_hex.c
SRC_ALL = $(SRC) $(SRC_LIBFT)

OPTIONS = -Wall -Wextra -Werror

LIBFT = cd libft && make && cd ..

all: $(NAME)

$(NAME):
	$(LIBFT) && gcc $(OPTIONS) -c $(SRC) && ar rcs $(NAME) $(SRC_ALL:.c=.o)

cleanlib:
	cd libft && make clean && cd ..

clean: cleanlib
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all