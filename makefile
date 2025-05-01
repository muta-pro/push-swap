NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Iheaders 
HEADER = ps.h
SRCS = main.c data_structure.c minisort.c parsing.c \
utils.c swap_instruct.c reverse_instruct.c\
rotate_instruct.c push_instruct.c stack_op.c positioning.c\
quick_s.c optima.c chunk_sort.c greedy.c cost_struct.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
$(LIBFT):
	make -C $(LIBFT_DIR)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f push_swap
re: fclean all