#include "fillit.h"

void		print_list(t_piece *cursor)
{
	if (cursor == NULL)
		ft_putendl("Error: Cursor is NULL.");
	else
	{
		ft_putnbr(cursor->x[0]);
		ft_putendl("");
		ft_putnbr(cursor->x[1]);
		ft_putendl("");
		ft_putnbr(cursor->x[2]);
		ft_putendl("");
		ft_putnbr(cursor->y[0]);
		ft_putendl("");
		ft_putnbr(cursor->y[1]);
		ft_putendl("");
		ft_putnbr(cursor->y[2]);
		ft_putendl("");
	}
}
