#include "libft.h"
#include "fillit.h"

void		add_piece(t_piece **alst, t_piece *new);

t_piece		*create_list(int *x, int *y);

int			main(void)
{
	int			x[3];
	int			y[3];
	t_piece		*ret;
	t_piece		*new;
	t_piece		*next_piece;

	x[0] = 1;
	x[1] = 2;
	x[2] = 3;
	y[0] = 4;
	y[1] = 5;
	y[2] = 6;
	ret = create_list(x, y);
	if (ret == NULL)
	{
		ft_putendl("Error: Programmer still doesn't know how to create and return a node.");
		return (-1);
	}
	ft_putnbr(ret->x[0]);
	ft_putendl("");
	ft_putnbr(ret->x[1]);
	ft_putendl("");
	ft_putnbr(ret->x[2]);
	ft_putendl("");
	ft_putnbr(ret->y[0]);
	ft_putendl("");
	ft_putnbr(ret->y[1]);
	ft_putendl("");
	ft_putnbr(ret->y[2]);
	x[0] = 7;
	x[1] = 8;
	x[2] = 9;
	y[0] = 10;
	y[1] = 11;
	y[2] = 12;
	new = create_list(x, y);
	add_piece(&ret, new);
	ft_putnbr(ret->x[0]);
	ft_putendl("");
	ft_putnbr(ret->x[1]);
	ft_putendl("");
	ft_putnbr(ret->x[2]);
	ft_putendl("");
	ft_putnbr(ret->y[0]);
	ft_putendl("");
	ft_putnbr(ret->y[1]);
	ft_putendl("");
	ft_putnbr(ret->y[2]);
	while (new)
		{
			next_piece = new->next;
			ft_putnbr(next_piece->x[0]);
		ft_putendl("");
		ft_putnbr(next_piece->x[1]);
		ft_putendl("");
		ft_putnbr(next_piece->x[2]);
		ft_putendl("");
		ft_putnbr(next_piece->y[0]);
		ft_putendl("");
		ft_putnbr(next_piece->y[1]);
		ft_putendl("");
		ft_putnbr(next_piece->y[2]);
		new = next_piece;
		}
	/*while (1)
	{

	}*/
	return (0);
}
