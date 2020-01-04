#include "libft.h"
#include "fillit.h"

t_piece		*create_list(int *x, int *y);

int			main(void)
{
	int			x[3];
	int			y[3];
	t_piece		*ret;

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
	free(ret);
	return (0);
}
