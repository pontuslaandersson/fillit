#include "fillit.h"

void	traverse(t_piece *head)
{
	t_piece	*cursor;
	   
	cursor = head;
    while (cursor != NULL)
    {
        print_list(cursor);
        cursor = cursor->next;
    }
}
