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

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I
SRCS = errors.c \
		init.c \
		main.c \
		push_swap_init.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		tiny.c \
		utils.c \

OBJS = $(SRCS:.c=.o)
RM = rm -f $(OBJS)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)
clean:
	$(RM)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re