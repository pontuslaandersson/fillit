#include "fillit.h"

int     check_candidate(t_piece *cursor, char **map, int x, int y)
{

    if (y + 1 == ft_strlen(map[0]) && x + 1 == ft_strlen(map[0]))
    {
        return (-1);
    }
    if ((y + (cursor->y[0])) < ft_strlen(map[0]) && (y + (cursor->y[1])) < ft_strlen(map[0]) && (y + (cursor->y[2])) < ft_strlen(map[0]))
    {
        if (map[y + cursor->y[0]][x + cursor->x[0]] == '.')
        {
            if (map[y + (cursor->y[1])][x + (cursor->x[1])] == '.')
            {

                if (map[y + (cursor->y[2])][x + (cursor->x[2])] == '.')
                {
                    map[y][x] = cursor->letter;
                    map[y + cursor->y[0]][x + cursor->x[0]] = cursor->letter;
                    map[y + cursor->y[1]][x + cursor->x[1]] = cursor->letter;
                    map[y + cursor->y[2]][x + cursor->x[2]] = cursor->letter;
			    	return (0);
                }
            }
        }
    }
    return (-1);
}
