# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 13:55:04 by xchalle           #+#    #+#              #
#    Updated: 2021/10/22 10:54:27 by xchalle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	libft/ft_atoi.c \
		src/algo_3.c \
		src/algo_5.c \
		src/algo_100_500.c \
		src/algo_rotate_stack.c \
		src/algo_reverse_stack.c \
		src/push.c \
		src/swap.c \
		src/reverse.c \
		src/rotate.c \
		src/create_stack.c \
		src/create_digit.c \
		src/create_tab.c \
		src/check_arg.c \
		src/index_list.c \
		src/main.c \
		src/utils.c \
		src/ft_split2.c \
		src/free.c \

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -I./include
CC = gcc $(CFLAGS)
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJ)
		$(CC) -o $@ $^

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
