#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <unistd.h>

typedef	struct		s_piece
{
	int			x[3];
	int			y[3];
	char		letter;
	struct s_piece	*next;
}					t_piece;

void	display_error(void);

#endif
