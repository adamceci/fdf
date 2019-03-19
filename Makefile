# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceciora <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 17:31:41 by aceciora          #+#    #+#              #
#    Updated: 2019/03/19 15:22:10 by aceciora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBS = -lmlx -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(MLX_HEADERS)

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADERS = $(LIBFT_DIR)includes/

MLX_DIR = ./minilibx_macos/
MLX = $(MLX_DIR)libmlx.a
MLX_HEADERS = $(MLX_DIR)

HEADERS_DIR = ./includes/
HEADERS_LIST = fdf2.h\
			   keys.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRCS_DIR = ./sources/
SRCS_LIST = main2.c					\
	   		read_map.c				\
	   		array.c					\
	   		modif_stack.c			\
	   		utils.c					\
	   		init.c					\
	   		draw.c					\
	   		rotate.c				\
	   		bresenham.c				\
	   		events.c				\
	   		events_list.c			\
	   		events_list2.c			\
	   		background_and_menu.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR = objects/
OBJS_LIST = $(SRCS_LIST:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))

# COLORS

NO_COLOR = \x1b[0m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
YELLOW = \x1b[33;01m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS_DIR) $(OBJS)
	@$(CC) $(FLAGS) $(LIBS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(NO_COLOR)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(NO_COLOR)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(NAME): $(GREEN)$(OBJS_DIR) was created$(NO_COLOR)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(NO_COLOR)\c"
	
$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(NO_COLOR)"
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	@echo "$(NAME): $(GREEN)Creating $(MLX)...$(NO_COLOR)"
	@$(MAKE) -sC $(MLX_DIR)

clean:
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(MAKE) clean -sC $(MLX_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "$(NAME): $(RED)$(OBJS_DIR) and object files were deleted$(NO_COLOR)"

fclean: clean
	@rm -f $(MLX)
	@echo "$(NAME): $(RED)$(MLX) was deleted$(NO_COLOR)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(NO_COLOR)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(NO_COLOR)"

re: fclean all
