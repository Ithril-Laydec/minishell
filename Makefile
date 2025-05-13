# Variables
NAME			=	minishell
CFLAGS			=	# -Wall -Wextra -Werror
NOPIE			=	-no-pie
RL				=	-lreadline
OBJ_DIR			=	obj
LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a
FT_PRINTF_DIR	= 	ft_printf
FT_PRINTF		= 	$(FT_PRINTF_DIR)/libftprintf.a

SRCS			=	$(shell find src -type f -name "*.c")
OBJS			=	$(SRCS:src/%.c=$(OBJ_DIR)/%.o)

# Colors
BLUE			=	\033[0;34m
GREEN			=	\033[0;32m
RED				=	\033[0;31m
NC				=	\033[0m

# Rules
all: $(NAME)


$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
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
	@make -C $(LIBFT_DIR) fclean
	@make -C  $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)
	@echo -n "$(NC)"

re: fclean all

clear:
	@clear

test: clear $(LIBFT) $(FT_PRINTF) $(NAME)
	./$(NAME)

tester: clear $(LIBFT) $(NAME)
	


.PHONY: all clean fclean re clear