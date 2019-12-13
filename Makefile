# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 11:30:19 by panderss          #+#    #+#              #
#    Updated: 2019/12/12 11:42:58 by panderss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft.a

SRC = 

INCLUDES = ./includes/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) -I ./includes/
	gcc -I libft/includes -L libft -lft main.c get_next_line.c

lib: 
	make -C libft/ fclean && make -C libft/ && make -C libft/ clean

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib
