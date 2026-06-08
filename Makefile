# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/08 22:10:46 by apolguil          #+#    #+#              #
#    Updated: 2026/06/08 23:05:52 by apolguil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = Libft/libft.a

SRCS = main.c push_swap.c \
	op_exec.c op_swap.c op_push.c op_rotate.c op_reverse_rotate.c \
	parsing.c init.c read_all_flags.c \
	sort_simple.c sort_complex.c sort_medium.c \
	sort_utils.c sort_adaptive.c print_bench.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C Libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C Libft clean

fclean: clean
	$(RM) $(NAME)
	make -C Libft fclean

re: fclean all

.PHONY: all clean fclean re