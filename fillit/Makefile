# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panderss <panderss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 11:30:19 by panderss          #+#    #+#              #
#    Updated: 2020/01/29 22:02:39 by panderss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft.a

SRC = 	add_link.c \
		add_piece.c \
		assign_letter.c \
		check_candidate.c \
		check_tetromino.c \
		create.c \
		create_list.c \
		create_map.c \
		display_error.c \
		find_dot.c \
		get_head.c \
		main.c \
		new_line.c \
		place_first.c \
		solve.c \
		solve_map.c \
		store_tetro.c \

INCLUDES = ./libft/includes/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: lib $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) -I $(INCLUDES)
	gcc -o $(NAME) $(OBJ) -L libft -lft -I $(INCLUDES)

lib: 
	make -C libft/ fclean && make -C libft/ && make -C libft/ clean

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib