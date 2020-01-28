#include "fillit.h"

/*void		delete(int *x, int *y, int letter)
{
	free(&x);
	free(&y);
	free(&letter);
}*/

void		del_list(t_piece *head)
{
	t_piece	*tmp;

	if (head != NULL)
	{
		while (head != NULL)
		{
			tmp = head;
			head = head->next;
			/*delete(cursor->x, cursor->y, cursor->letter);*/
			free(tmp);
		}
	}
}
