NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Iheaders 
HEADER = ps.h
SRCS = src/main.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
$(LIBFT)
	make -C $(LIBFT_DIR)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(LIBFT_DIR) push_swap
re: fclean all