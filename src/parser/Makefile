NAME = parser
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
SANITIZER = $(CC) $(FLAGS) -fsanitize=address

SRC = $(shell find -name "*.c")

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@clear

%.o:%.c
	@clear
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $^ -o $@

clean:
	@clear
	@$(RM) $(OBJ)

fclean: clean
	@clear
	@$(RM) $(NAME)

re: fclean all

gdb: $(OBJ)
	@clear
	@$(CC) $(FLAGS) -g $^ -o $@
	@gdb ./$(NAME)

sanitizer:
	@clear
	@$(SANITIZER) -c $(OBJ) -o $(SRC)

test: all
	@clear
	@./$(NAME) "echo hello world" | cat -e
	@echo "\n"
#	@./$(NAME) 

.PHONY: all clean fclean re gdb sanitizer test