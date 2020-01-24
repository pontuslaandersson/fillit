#include "fillit.h"

void	traverse(t_piece *head)
{
	t_piece	*cursor;
	   
	cursor = head;
    while (cursor != NULL)
    {
/*		ft_putendl("* Printing a set of coordinates..."); */
        print_list(cursor);
        cursor = cursor->next;
    }
}
