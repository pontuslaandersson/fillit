#include "fillit.h"

void       free_map(char **map)
{
    int     i;
    int     limit;

    i = 0;
    limit = ft_strlen(map[0]);
    if (map != NULL)
    {
        while (i < limit)
        {
            ft_strdel(&map[i]);
            ++i;
        }
    }
}