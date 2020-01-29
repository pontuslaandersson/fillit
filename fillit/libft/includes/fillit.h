/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:32:32 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 21:59:56 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 8
# define FD_MAX 4864

# include "libft.h"
# include <stdio.h>

typedef	struct		s_piece
{
	int				x[3];
	int				y[3];
	int				letter;
	struct s_piece	*prev;
	struct s_piece	*next;
}					t_piece;

t_piece				*assign_letter(t_piece *head, int n);
void				print_map(char **map);
char				**create_map(int n);
char				**initialize_map(int newlines);
int					check_candidate(t_piece *cursor, char **map, int x, int y);
int					check_tetrominos(char *file);
int					find_dot(t_piece *cursor, char **map, int x, int y);
void				new_line(char *file, char **grid, int lines_read);
int					place_first(t_piece *head, char **map, int x, int y);
int					place_piece(t_piece *head, char **map, int placed, int n,
					int start);
void				del_list(t_piece *head);
void				display_error(void);
void				free_map(char **map);
void				print_list(t_piece *cursor);
void				solve(t_piece *head, int newlines);
int					solve_map(t_piece *cursor, char **map, int x, int y);
t_piece				*add_link(t_piece *start, char **grid, int n);
t_piece				*create_list(int *x, int *y);
t_piece				*create(int *x, int *y, t_piece *prev);
t_piece				*add_piece(t_piece *ret, int *x, int *y);
t_piece				*find_coords(char **grid);
t_piece				*get_head(char *file);
t_piece				*save_coords(char **grid, int j, int i);
t_piece				*store_tetro(char *file, int newlines);

#endif
