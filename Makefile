FILES = main.c push_swap.c check_input.c
OBJECTS = $(FILES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap.a
PRINTF = $(PRINTF_PATH)/ft_printf.a
PRINTF_PATH = ./ft_printf
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_PATH = ./libft

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(FILES) -o a.out

$(PRINTF):
	make -C $(PRINTF_PATH) 

$(LIBFT):
	make bonus -C $(LIBFT_PATH)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	make clean -C $(PRINTF_PATH) 
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJECTS) $(B_OBJECTS)

fclean: clean
	make fclean -C $(PRINTF_PATH) 
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all