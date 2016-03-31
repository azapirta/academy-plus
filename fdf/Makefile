# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azapirta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/12 10:07:37 by azapirta          #+#    #+#              #
#    Updated: 2016/03/31 16:20:55 by azapirta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	srcs/draw_map.c \
		srcs/main.c \
		srcs/compute_projections.c \
		srcs/get_coords.c \
		srcs/read_matrix.c \

OBJ =	draw_map.o \
		main.o \
		compute_projections.o \
		get_coords.o \
		read_matrix.o \

FLAGS = -Wall -Wextra -Werror

CC = -gcc $(FLAGS)

MLX = -L includes/minilibx_macos -lmlx -framework OpenGL -framework AppKit

LIBFT = -L libft -lft

all: $(NAME)

$(NAME) :
	@make -C libft/
	@$(CC) $(SRCS) -c -I ./includes
	@$(CC) $(OBJ) -o $(NAME) $(MLX) $(LIBFT)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(OBJ) $(NAME)

re: fclean all

