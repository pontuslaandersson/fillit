#include "fillit.h"

t_piece		*traverse_until(t_piece *head, int n)
{
	t_piece	*cursor;
	int		i;

	i = 0;
	cursor = head;
    while (cursor->next != NULL && i < n)
    {
        cursor = cursor->next;
		++i;
    }
	return (cursor);
}

t_piece		*assign_letter(t_piece *head, int n)
{
	t_piece *cursor;

	cursor = traverse_until(head, n);
	cursor->letter = 65 + n;
	return (head);
}