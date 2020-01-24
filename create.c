#include "libft.h"
#include "fillit.h"

t_piece     *create(int *x, int *y, t_piece *prev, t_piece *next, int n)
{
    int len;

    t_piece     *new_node = (t_piece*)malloc(sizeof(t_piece));
    if(new_node == NULL)
    {
/*        ft_putendl("Error creating a new node."); */
        return (NULL);
    }
    len = 0;
	while (len < 3)
	{
		new_node->x[len] = x[len];
		++len;
	}
    len = 0;
	while (len < 3)
	{
		new_node->y[len] = y[len];
		++len;
	}
    new_node->letter = 65 + n;
    new_node->prev = prev;
    new_node->next = next;
 
    return (new_node);
}
