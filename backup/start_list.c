#include "fillit.h"

t_piece		*start_list(int *x, int *y)
{
	t_piece *start;

	start = create_list(x, y);
	return (start);
}