NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ift_printf

SRC = chunksort.c ft_node.c ft_push_swap.c swap.c utils.c \
	ft_validation.c ft_string_utils.c ft_parse_args.c ft_sort_small.c \
	ft_printf/ft_printf.c ft_printf/ft_putchar.c \
	ft_printf/ft_puthex.c ft_printf/ft_putnbr_u.c \
	ft_printf/ft_putnbr.c ft_printf/ft_putstr.c \
	moreutils.c \
	moremoreutils.c \

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)
	@echo "Bonus compilato con successo"