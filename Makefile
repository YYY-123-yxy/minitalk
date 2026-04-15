CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

SERVER = server
CLIENT = client

all: $(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

$(LIBFT):
	make -C libft
	
$(PRINTF):
	make -C ft_printf

$(SERVER): server.c
	$(CC) $(CFLAGS) server.c $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT): client.c
	$(CC) $(CFLAGS) client.c $(LIBFT) $(PRINTF) -o $(CLIENT)

clean:
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re
