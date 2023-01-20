FILES = main.c push_swap.c check_input.c throw_error.c stack_utils.c commands.c print_cmd.c sort_three.c stack.c sort_big.c helpers.c
OBJECTS = $(addprefix obj/, $(FILES:.c=.o))
CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb3
NAME = push_swap
PRINTF = ft_printf/ft_printf.a
LIBFT = libft/libft.a
INCLUDES = -I ft_printf/includes -I libft/includes
MAKE = make -j4

all: $(NAME)

$(NAME): $(PRINTF) $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(PRINTF) $(LIBFT) $(INCLUDES) -o $(NAME)

$(PRINTF):
	$(MAKE) -C ft_printf

$(LIBFT):
	$(MAKE) -C libft

obj/%.o: %.c
	mkdir -p obj
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(MAKE) -C ft_printf clean
	$(MAKE) -C libft clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean
	$(MAKE) all