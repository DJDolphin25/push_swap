# Nombre de la librería
NAME = libft.a

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

# Archivos fuente de libft
LIBFT_SRC = src/libft/ft_atoi.c \
            src/libft/ft_bzero.c \
            src/libft/ft_calloc.c \
            src/libft/ft_isalnum.c \
            src/libft/ft_isalpha.c \
            src/libft/ft_isascii.c \
            src/libft/ft_isdigit.c \
            src/libft/ft_isprint.c \
            src/libft/ft_itoa.c \
            src/libft/ft_memchr.c \
            src/libft/ft_memcmp.c \
            src/libft/ft_memcpy.c \
            src/libft/ft_memmove.c \
            src/libft/ft_memset.c \
            src/libft/ft_strchr.c \
            src/libft/ft_strdup.c \
            src/libft/ft_strlcat.c \
            src/libft/ft_strlcpy.c \
            src/libft/ft_strlen.c \
            src/libft/ft_strncmp.c \
            src/libft/ft_strnstr.c \
            src/libft/ft_strrchr.c \
            src/libft/ft_tolower.c \
            src/libft/ft_toupper.c \
            src/libft/ft_substr.c \
            src/libft/ft_strjoin.c \
            src/libft/ft_strtrim.c \
            src/libft/ft_split.c \
            src/libft/ft_strmapi.c \
            src/libft/ft_striteri.c \
            src/libft/ft_putchar_fd.c \
            src/libft/ft_putstr_fd.c \
            src/libft/ft_putendl_fd.c \
            src/libft/ft_putnbr_fd.c

# Archivos fuente de ft_printf
PRINTF_SRC = src/ft_printf/parser.c \
             src/ft_printf/print_char.c \
             src/ft_printf/print_decimal.c \
             src/ft_printf/print_string.c \
             src/ft_printf/print_unsigned_decimal.c \
             src/ft_printf/print_hex_lowercase.c \
             src/ft_printf/print_hex_uppercase.c \
             src/ft_printf/print_memory.c \

# Archivos fuente de get_next_line
GNL_SRC = src/get_next_line/get_next_line.c \
          src/get_next_line/get_next_line_utils.c

# Todos los sources
SRC = $(LIBFT_SRC) $(PRINTF_SRC) $(GNL_SRC)

# Archivos objeto
OBJ = $(SRC:.c=.o)

# PHONY rules
.PHONY: all clean fclean re

# Regla por defecto
all: $(NAME)

# Crear librería estática
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "✅ $(NAME) creado correctamente ✅"

# Compilar cada .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar objetos
clean:
	rm -f $(OBJ)

# Limpiar todo (objetos + librería)
fclean: clean
	rm -f $(NAME)

# Reconstruir desde cero
re: fclean all
