#include "fillit.h"

t_piece		*traverse_until(t_piece *head, int piece)
{
	t_piece	*cursor;
	int		i;

	i = 0;
	cursor = head;
    while (cursor->next != NULL || i < piece)
    {
        cursor = cursor->next;
		++i;
    }
	return (cursor);
}
