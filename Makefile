# Name of the library
NAME = push_swap

# Compilator and flags
CC = cc
INCLUDES = -I .
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

# Source files
SRC = srcs/lst_utils.c \
	srcs/lst_utils2.c \
	
			
OBJ = $(SRC:.c=.o)

# Compile each .c to .o
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all test

# Rule by defect
all: $(NAME)

# Create static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "✅ $(NAME) has been successfully created ✅"

# Clean objects
clean:
	rm -f $(OBJ)

# Clean everything(objects + library)
fclean: clean
	rm -f $(NAME)

# Rebuild everything form zero
re: fclean all

# To test
test: $(NAME)
	$(CC) $(CFLAGS) testprintf.c $(NAME) -o test

