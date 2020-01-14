#include "fillit.h"

void    solve(t_piece *head, int newlines)
{
    static char    **map;
    int     ret;
    int     placed;
    
    placed = 0;
    map = initialize_map(newlines);
    ft_putendl("Sending to place_piece...");
    ret = place_piece(head, map, placed);
    print_map(map);
    
}