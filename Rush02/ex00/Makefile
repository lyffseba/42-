# Compiler to use
CC = gcc

# Compiler flags: enable all warnings and treat them as errors
CFLAGS = -Wall -Wextra -Werror

# Name of the executable
NAME = rush-02

# Source files to compile
SRCS = rush-02.c dict.c numbers_to_words.c utils.c

# Object files generated from source files
OBJS = $(SRCS:.c=.o)

# Default target: build the executable
all: $(NAME)

# Link object files to create the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compile each .c file to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Declare targets as phony
.PHONY: all clean fclean re
