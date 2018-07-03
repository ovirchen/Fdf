# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:45:37 by ovirchen          #+#    #+#              #
#    Updated: 2017/10/25 12:45:38 by ovirchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = 	main.c \
		check_map.c \
		draw.c \
		move.c \
		iso_parallel.c \
		rotate.c \
		key_hook.c \
		text.c \
		zoom.c \
		
CC = gcc -g -Wall -Werror -Wextra

OBJ = $(SRCS:%.c=%.o)

HEADERS = fdf.h libft/libft.h

FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) libft/libft.a $(FLAGS)

$(OBJ): $(SRCS)
	@$(CC) -c $(SRCS) -I $(HEADERS)

clean:
	@rm -f $(OBJ)
	@rm -f libft/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re