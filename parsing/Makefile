NAME = parser
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
SANITIZER = $(CC) $(FLAGS) -fsanitize=address

SRC = main.c \
		libft/ft_split.c \
		libft/ft_substr.c \
		libft/ft_strdup.c \
		libft/ft_itoa.c \
		libft/ft_strtrim.c \
		libft/parser_libft.c \
		parser_finder.c \
		parser_utils.c \
		parser_check_content.c \
		parser_env_expand.c \
		parser_level_0.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@clear

%.o:%.c
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