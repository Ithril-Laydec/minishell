# Variables
NAME			=	minishell
CFLAGS			=	-Wall -Wextra -Werror
NOPIE			=	-no-pie
RL				=	-lreadline
OBJ_DIR			=	obj
LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a

SRCS			=	$(shell find src -type f -name "*.c")
OBJS			=	$(SRCS:src/%.c=$(OBJ_DIR)/%.o)

# Colors
BLUE			=	\033[0;34m
GREEN			=	\033[0;32m
RED				=	\033[0;31m
NC				=	\033[0m

# Rules
all: $(NAME)

.PHONY: libft

libft:
	@make --no-print-directory -C $(LIBFT_DIR)

$(LIBFT): libft

$(NAME): clear $(LIBFT) $(OBJS)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -g -o $(NAME) $(RL) $(NOPIE)
	@echo "$(GREEN)$(NAME) created$(NC)"

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo -n "$(BLUE)"
	cc $(CFLAGS) -c $< -o $@
	@echo -n "$(NC)"

clean:
	@echo -n "$(RED)"
	rm -rf obj
	@echo -n "$(NC)"

fclean: clean
	@echo -n "$(RED)"
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	@echo -n "$(NC)"

re: fclean all

clear:
	@clear

test: clear $(LIBFT) $(NAME)
	./$(NAME)

tester: clear $(LIBFT) $(NAME)
	cd minishell_tester && bash -c "./tester | sed 's/\x1b\[[0-9;]*m//g' | tee errors.txt"
	@cd minishell_tester && sed -i '/Test.*✅/d' errors.txt
	@echo "$(GREEN)Errors results saved to minishell_tester/errors.txt$(NC)"

debug: $(LIBFT) $(OBJS)
	cc $(CFLAGS) -g $(OBJS) $(LIBFT) -o $(NAME) $(RL) $(NOPIE)
	gdb ./$(NAME)

sanityzer: $(LIBFT) $(OBJS)
	@cc -fsanitize=address -g $(OBJS) $(LIBFT) -o $(NAME) $(RL) $(NOPIE)
	./$(NAME)

valdgrind: $(LIBFT) $(OBJS) $(NAME)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)


.PHONY: all clean fclean re clear libft