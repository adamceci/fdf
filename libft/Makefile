#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 13:39:23 by vbrazhni          #+#    #+#              #
#    Updated: 2019/03/14 17:35:26 by aceciora         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -c

INCLUDES = -I$(HEADERS_DIR)
HEADERS_LIST = libft.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRCS_DIR = ./sources/
SRCS_LIST = ft_memset.c			\
			ft_bzero.c			\
			ft_memcpy.c			\
			ft_memccpy.c		\
			ft_memmove.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_strlen.c			\
			ft_strdup.c			\
			ft_strcpy.c			\
			ft_strncpy.c		\
			ft_strcat.c			\
			ft_strncat.c		\
			ft_strlcat.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strstr.c			\
			ft_strnstr.c		\
			ft_strcmp.c			\
			ft_strncmp.c		\
			ft_atoi.c			\
			ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_memalloc.c		\
			ft_memdel.c			\
			ft_strnew.c			\
			ft_strdel.c			\
			ft_strclr.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strequ.c			\
			ft_strnequ.c		\
			ft_strsub.c			\
			ft_strjoin.c		\
			ft_strjoin_free.c	\
			ft_strtrim.c		\
			ft_strsplit.c		\
			ft_itoa.c			\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_putendl.c		\
			ft_putnbr.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_lstnew.c			\
			ft_lstdelone.c		\
			ft_lstdel.c			\
			ft_lstadd.c			\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_lstappend.c		\
			ft_strupper.c		\
			ft_strlower.c		\
			ft_isspace.c		\
			ft_bubble_sort.c	\
			ft_sqrt.c			\
			ft_swap.c			\
			get_next_line.c		\
			free_2d_array.c
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

$(NAME): $(OBJS_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(NO_COLOR)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(NO_COLOR)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(NAME): $(GREEN)$(OBJS_DIR) was created$(NO_COLOR)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(NO_COLOR)\c"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(NAME): $(RED)$(OBJS_DIR) was deleted$(NO_COLOR)"
	@echo "$(NAME): $(RED)object files were deleted$(NO_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(NO_COLOR)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
