#include "libft.h"
#include "fillit.h"

/* Tester to make sure the  */

int			main(void)
{
	int			x[3];
	int			y[3];
	t_piece		*ret;
	t_piece		*new;

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
	ft_putendl("Coordinates stored in ret node:");
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
	ft_putendl("");
	x[0] = 7;
	x[1] = 8;
	x[2] = 9;
	y[0] = 10;
	y[1] = 11;
	y[2] = 12;
	/*new = create_list(x, y);*/
	ft_putendl("Adding second node with coordinates 7-12...");
	add_piece(ret, x, y);
	/*ft_putendl("Navigating to new node.");
	ret = ret->next;*/
	ft_putendl("Attempting to traverse and print values stored in linked list.");
	traverse(ret);
	ft_putendl("Attempting to traverse in reverse and print values.");
	traverse_rev(ret);
	/*ft_putendl("Coordinates stored in ret node, again:");
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
	ft_putendl("");*/
	return (0);
}
