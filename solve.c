#include "fillit.h"

void       free_map(char **map)
{
    /*int     i;*/
    int     limit,

    i = 0;
    limit = ft_strlen(map[0]);
    if (map != NULL)
    {
        while (i < limit)
        {
            ft_putendl("Attempting to free line...");
            ft_strdel(&map[i]);
            ft_putendl("Line freed!");
            ++i;
        }
        /*free(&map);*/
        ft_putendl("Map freed!");
    }
}

void    solve(t_piece *head, int newlines, int max)
{
    static char    **map;
    int            ret;
    int            placed;
    
    placed = 0;
    ft_putstr("Max: ");
    ft_putnbr(max);
    ft_putendl("");
    map = initialize_map(newlines);
    ft_putendl("Sending to place_piece...");
    while (placed < max)
    {
        ret = place_piece(head, map, placed);
        if (ret == -1)
            break ;
        ++placed;
        print_map(map);
    }
    if (ret == -1)
    {
        print_map(map);
        /*while (1)
            {

            }*/
        free_map(map);
        solve(head, newlines + 5, max);
    }
    if (ret != -1)
        print_map(map);
    ft_putendl("Reached end of solve function, going to main."); 
}