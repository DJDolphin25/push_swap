NAME = push_swap
LIBFT = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -I srcs/libft/includes

# Sources push_swap

PUSH_SRC = srcs/lst_utils.c \
           srcs/lst_utils2.c \
           srcs/main.c \
           srcs/parser.c \
	   srcs/rules.c

PUSH_OBJ = $(PUSH_SRC:.c=.o)


#LIBFT SOURCES
LIBFT_SRC = srcs/libft/src/libft/ft_atoi.c \
            srcs/libft/src/libft/ft_bzero.c \
            srcs/libft/src/libft/ft_calloc.c \
            srcs/libft/src/libft/ft_isalnum.c \
            srcs/libft/src/libft/ft_isalpha.c \
            srcs/libft/src/libft/ft_isascii.c \
            srcs/libft/src/libft/ft_isdigit.c \
            srcs/libft/src/libft/ft_isprint.c \
            srcs/libft/src/libft/ft_itoa.c \
            srcs/libft/src/libft/ft_memchr.c \
            srcs/libft/src/libft/ft_memcmp.c \
            srcs/libft/src/libft/ft_memcpy.c \
            srcs/libft/src/libft/ft_memmove.c \
            srcs/libft/src/libft/ft_memset.c \
            srcs/libft/src/libft/ft_strchr.c \
            srcs/libft/src/libft/ft_strdup.c \
            srcs/libft/src/libft/ft_strlcat.c \
            srcs/libft/src/libft/ft_strlcpy.c \
            srcs/libft/src/libft/ft_strlen.c \
            srcs/libft/src/libft/ft_strncmp.c \
            srcs/libft/src/libft/ft_strnstr.c \
            srcs/libft/src/libft/ft_strrchr.c \
            srcs/libft/src/libft/ft_tolower.c \
            srcs/libft/src/libft/ft_toupper.c \
            srcs/libft/src/libft/ft_substr.c \
            srcs/libft/src/libft/ft_strjoin.c \
            srcs/libft/src/libft/ft_strtrim.c \
            srcs/libft/src/libft/ft_split.c \
            srcs/libft/src/libft/ft_strmapi.c \
            srcs/libft/src/libft/ft_striteri.c \
            srcs/libft/src/libft/ft_putchar_fd.c \
            srcs/libft/src/libft/ft_putstr_fd.c \
            srcs/libft/src/libft/ft_putendl_fd.c \
            srcs/libft/src/libft/ft_putnbr_fd.c \
            srcs/libft/src/ft_printf/parser.c \
            srcs/libft/src/ft_printf/print_char.c \
            srcs/libft/src/ft_printf/print_decimal.c \
            srcs/libft/src/ft_printf/print_string.c \
            srcs/libft/src/ft_printf/print_unsigned_decimal.c \
            srcs/libft/src/ft_printf/print_hex_lowercase.c \
            srcs/libft/src/ft_printf/print_hex_uppercase.c \
            srcs/libft/src/ft_printf/print_memory.c \
            srcs/libft/src/get_next_line/get_next_line.c \
            srcs/libft/src/get_next_line/get_next_line_utils.c

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

# PHONY rules

.PHONY: all clean fclean re libft


# Regla por defecto

all: $(NAME)

# Compilar push_swap + link con libft.a

$(NAME): $(PUSH_OBJ)
	$(MAKE) -C srcs/libft
	$(CC) $(CFLAGS) $(PUSH_OBJ) srcs/libft/libft.a -o $(NAME)
	@echo "✅ $(NAME) compilado y linkeado con libft ✅"


# Librería libft.a

libft.a: $(LIBFT_OBJ)
	ar rcs $(LIBFT) $(LIBFT_OBJ)
	@echo "✅ Librería $(LIBFT) creada ✅"


# Compilar objetos individuales

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar objetos

clean:
	rm -f $(PUSH_OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all
