CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all: $(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

bonus: $(LIBFT) $(PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
	make -C libft
	
$(PRINTF):
	make -C ft_printf

$(SERVER): server.c
	$(CC) $(CFLAGS) server.c $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT): client.c
	$(CC) $(CFLAGS) client.c $(LIBFT) $(PRINTF) -o $(CLIENT)

$(SERVER_BONUS): server_bonus.c
	$(CC) $(CFLAGS) server_bonus.c $(LIBFT) $(PRINTF) -o $(SERVER_BONUS)

$(CLIENT_BONUS): client_bonus.c
	$(CC) $(CFLAGS) client_bonus.c $(LIBFT) $(PRINTF) -o $(CLIENT_BONUS)

clean:
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

.PHONY: all bonus clean fclean re
