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
	@make -C $(LIBFT_DIR) > /dev/null
	@echo "\t\t\tOK"

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) > /dev/null
	@echo "\t\t\tOK"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) > /dev/null
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null
	@echo "\t\t\tOK"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR) > /dev/null
	@make -C $(LIBFT_DIR) clean > /dev/null
	@echo "\t\t\tOK"

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME) > /dev/null
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@echo "\t\t\tOK"

re: fclean all

.PHONY: all clean fclean re clear test
