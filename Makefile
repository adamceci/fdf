NAME = fdf

SRCS = main.c		\
	   fdf.c		\
	   init_mlx.c	\

OBJS = $(SRCS:%.c=%.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = fdf.h

LIB = ./libft

MLX = ./minilibx_macos

all: $(NAME)

$(NAME):
	@make re -C $(LIB)
	@make re -C $(MLX)
	$(CC) -c $(SRCS) $(HEADER) -I $(LIB)/includes -I $(MLX)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB) -lft -L $(MLX) -lmlx -framework OpenGL -framework Appkit

clean:
	@make clean -C $(LIB)
	@make clean -C $(MLX)
	/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIB)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
