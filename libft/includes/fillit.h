/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:32:32 by panderss          #+#    #+#             */
/*   Updated: 2020/01/07 22:12:58 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 8
# define FD_MAX 4864

# include "libft.h"

typedef	struct		s_piece
{
	int				x[3];
	int				y[3];
	char			letter;
	struct s_piece	*prev;
	struct s_piece	*next;
}					t_piece;

void		print_map(char **map);
char		**create_map(int n);
char		**initialize_map(int newlines);
int			new_line(char *file, char **grid, int lines_read);
int     	place_piece(t_piece *head, char **map, int placed);
void		display_error(void);
void		traverse(t_piece* head);
void		traverse_rev(t_piece* head);
void		print_list(t_piece *cursor);
void    	solve(t_piece *head, int newlines);
t_piece		*create_list(int *x, int *y);
t_piece		*create(int *x, int *y, t_piece *prev, t_piece *next);
t_piece		*add_piece(t_piece *ret, int *x, int *y);
t_piece		*find_coords(char **grid);

#endif
