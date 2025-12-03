# Executable names
SERVER = server
CLIENT = client

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Object files
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# Default target
all: $(LIBFT) $(SERVER) $(CLIENT)

# Build libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Build server
$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFT_DIR) -lft -o $(SERVER)

# Build client
$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFT_DIR) -lft -o $(CLIENT)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

# Clean object files
clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

# Clean everything
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(SERVER) $(CLIENT)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
