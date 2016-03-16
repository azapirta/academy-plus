# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azapirta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/12 10:07:37 by azapirta          #+#    #+#              #
#    Updated: 2016/03/12 10:11:49 by azapirta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/*.c

OBJ = *.o

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

