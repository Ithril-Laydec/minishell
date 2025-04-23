# Variables
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LEAKS	= -fsanitize=address
NAME	= libft.a

SRCS			=	$(shell find src -type f -name "*.c")

OBJS	= $(SRCS:src/%.c=obj/%.o)

TEST_SRCS = $(shell [ -d test ] && find test -type f -name "test_*.c" || echo "")
TEST_OBJS = $(TEST_SRCS:%.c=obj/%.o)

# Colores
BLUE		=	\033[0;34m
GREEN		=	\033[0;32m
RED			=	\033[0;31m
NC			=	\033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)libft.a created$(NC)"

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo -n "$(BLUE)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "$(NC)"

clean:
	@echo -n "$(RED)"
	rm -rf obj
	@echo -n "$(NC)"

fclean: clean
	@echo -n "$(RED)"
	rm -f $(NAME)
	@echo -n "$(NC)"

re: fclean all

test: LDFLAGS += -lbsd
test: $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(LEAKS) -o test/test_main $(OBJS) $(TEST_OBJS) $(LDFLAGS)
	clear
	@./test/test_main
	@rm -f obj/*.o
	@norminette -R CheckForbiddenSourceHeader --use-gitignore | grep "Error" | sed 's/^/\x1b[33m/; s/$$/\x1b[0m/'


# Phony
.PHONY: all clean fclean re test
