#include "fillit.h"

void	traverse_rev(t_piece* head)
{
	t_piece	*cursor;
	
	cursor = head;
	ft_putendl("* Going to end of list to test reverse print...");
    while(cursor->next != NULL)
    {
		ft_putendl("** Moving cursor...");
        cursor = cursor->next;
    }
	ft_putendl("* End of list reached; preparing to reverse.");
    /*ft_putendl("** Moving cursor backwards one step.");
	cursor = cursor->prev;
	ft_putendl("* Printing a set of coordinates...");
    print_list(cursor);*/
	while(cursor != NULL)
    {
		ft_putendl("* Printing a set of coordinates...");
        print_list(cursor);
		ft_putendl("** Moving cursor backwards.");
		cursor = cursor->prev;
    }
	if (cursor == NULL)
		ft_putendl("Cursor reached NULL pointer signifying beginning of list read in reverse. Sucessfully accessed list in reverse!");
}
