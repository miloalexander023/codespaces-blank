NAME = so_long.a

CC = gcc

CFLAGS	= -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lX11 -lXext -lm

MLX_SRCS	= $(wildcard minilibx-linux/*.c)
SRCS	= main.c

MLX_OBJ = $(MLX_SRCS:.c=.o)
OBJ = $(SRCS:.c=.o)

all: $(CC) $(CFLAGS) $(SRCS) $(MLX_FLAGS) $(MLX_SRCS) $(NAME)

$(NAME): $(OBJ) $(MLX_OBJ)
	ar rcs $(NAME) $(OBJ) $(MLX_OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)
	rm -f $(MLX_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean