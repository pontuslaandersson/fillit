#include "fillit.h"

void    solve(t_piece *head, int newlines)
{
    static char    **map;
    int            ret;
    int            placed;
    
    placed = 0;
    map = initialize_map(newlines);
    ft_putendl("Sending to place_piece...");
    while (placed < ((newlines + 1) / 5))
    {
        ret = place_piece(head, map, placed);
        if (ret == -1)
            break ;
        ++placed;
    }
    if (ret == -1)
    {
        /*free map*/
        solve(head, newlines + 5);
    }
    if (ret != -1)
        print_map(map);
}