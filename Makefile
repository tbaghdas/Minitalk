SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_LIB = src/ft_atoi.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o) $(SRC_LIB:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o) $(SRC_LIB:.c=.o)


all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER) 

$(CLIENT): $(OBJ_CLIENT) 
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJ_SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(OBJ_CLIENT_BONUS)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)


fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)


re: fclean all

rebonus: fclean bonus

.PHONY: clean fclean re all bonus rebonus