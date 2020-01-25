\
#include "fillit.h"

void	traverse_rev(t_piece* head)
{
	t_piece	*cursor;
	
	cursor = head;
    while(cursor->next != NULL)
    {
        cursor = cursor->next;
    }
	while(cursor != NULL)
    {
        print_list(cursor);
		cursor = cursor->prev;
    }
	if (cursor == NULL)
		ft_putendl("Cursor reached NULL pointer signifying beginning of list read in reverse. Sucessfully accessed list in reverse!");
}
