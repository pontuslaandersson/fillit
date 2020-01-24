# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panderss <panderss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 11:30:19 by panderss          #+#    #+#              #
#    Updated: 2020/01/24 11:36:45 by panderss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft.a

SRC = add_piece.c \
	  add_link.c \
	  get_head.c \
	  place_first.c \
	  find_dot.c \
	  check_candidate.c \
	  print_map.c \
	  solve.c \
	  solve_map.c \
	  initialize_map.c \
	  create_map.c \
	  new_line.c \
	  create.c \
	  create_list.c \
	  print_list.c \
	  store_tetro.c \
	  main.c \
	  check_tetromino.c \
	  display_error.c 

INCLUDES = ./libft/includes/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: lib $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) -I $(INCLUDES)
	gcc -o $(NAME) -L libft -lft -I $(INCLUDES)

lib: 
	make -C libft/ fclean && make -C libft/ && make -C libft/ clean

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib
