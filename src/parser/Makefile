# ** VARIABLES **

NAME            = parser
CC              = gcc
CFLAGS          = -Wall -Wextra -Werror -g
SRC_DIR         = .
OBJ_DIR         = ./obj
LIBFT_DIR       = ../../libft
LIBFT           = $(LIBFT_DIR)/libft.a
SRCS            = parser.c \
					command_parser.c \
					parsing_memmory_handling.c \
					parsing_utils.c
OBJS            = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# ** RULES **

all: $(NAME)

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_DIR)
	@echo "\t\t\tOK"

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\t\t\tOK"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\t\t\tOK"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@echo "\t\t\tOK"

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@echo "\t\t\tOK"

re: fclean all

clear:
	@clear

test: clear $(LIBFT) $(NAME)
	@echo "Running tests..."
	@./$(NAME)
	@echo "\t\t\tOK"

.PHONY: all clean fclean re clear test
