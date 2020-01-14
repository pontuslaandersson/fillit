#include "fillit.h"

t_piece		*traverse_until(t_piece *head, int piece)
{
	t_piece	*cursor;
	int		i;
	   
	cursor = head;
    while (cursor != NULL || i < piece)
    {
        print_list(cursor);
        cursor = cursor->next;
		++i;
    }
	return (cursor);
}
