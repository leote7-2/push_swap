# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 15:24:02 by jhenriq2          #+#    #+#              #
#    Updated: 2024/09/10 15:50:24 by jhenriq2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = 	src/commands/push.c \
		src/commands/reverse_rotate.c \
		src/commands/rotate.c \
		src/commands/swap.c \
		src/errors.c \
		src/init.c \
		src/main.c \
		src/move.c \
		src/push_swap_init.c \
		src/sort.c \
		src/tiny.c \
		src/utils.c \

OBJS = $(SRCS:.c=.o)
RM = rm -f $(OBJS)
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@echo " [...] | COMPILING..."
	@make -s -C $(LIBFT_PATH)
	@echo "[ OK ] | READY!"

clean:
	$(RM)
fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
re: fclean all

.PHONY: all clean fclean re