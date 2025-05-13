# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 21:42:42 by aternero          #+#    #+#              #
#    Updated: 2024/06/12 21:43:12 by aternero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

SOURCES = ft_printf.c\
ft_printchar.c\
ft_printhexl.c\
ft_printhexu.c\
ft_printnbr.c\
ft_printptr.c\
ft_printstr.c\
ft_printunsigned.c\


OBJECTS =  $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all clean fclean re