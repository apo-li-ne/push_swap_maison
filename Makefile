NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = Libft/libft.a

SRCS = main.c op.c parsing.c init.c read_all_flags.c \
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