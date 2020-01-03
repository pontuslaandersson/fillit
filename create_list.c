#include "libft.h"

t_list		*ft_create_list(const int *x, const int *y)
{
	t_list	*new;

	new = (t_list*)ft_memalloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
	}
	else
	{
		new->x = (int*)malloc(sizeof(size_t) * int);
		if (new->x == NULL)
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->x, x, 3);
        new->y = (int*)malloc(sizeof(size_t) * int);
		if (new->x == NULL)
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->y, y, 3)
	}
	new->next = NULL;
	return (new);
}
