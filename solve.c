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
            ft_putendl("Attempting to free line...");
            ft_strdel(&map[i]);
            ft_putendl("Line freed!");
            ++i;
        }
        /*free(&map);*/
        ft_putendl("Map freed!");
    }
}

void    solve(t_piece *head, int newlines, int max, int n, int start)
{
    static char             **map;
    int                     ret;
    static int              placed;
    static int              solved;
    
    solved = 0;
    placed = start;
    ft_putstr("Max: ");
    ft_putnbr(max);
    ft_putendl("");
    map = initialize_map(newlines);
    ft_putendl("Sending to place_piece...");
    if (placed == 0)
    {
        ret = place_piece(head, map, placed, n, start);
        if (ret == -1)
        {
            free_map(map);
            solve(head, newlines + 5, max, n, start);
        }
        ++placed;
    }
    if (placed > 0)
    {
        while (placed < max)
        {
            ret = place_piece(head, map, placed, n, start);
            if (ret == -1)
                break ;
            ++placed;
        }
    }
    /*if (ret == -2)
    {
        print_map(map);
        free_map(map);
        solve(head, newlines, max, n + 1, start);
    }*/
    /*if (ret == -1)
    {
        print_map(map);
        free_map(map);
        solve(head, newlines + 5, max, n, start);
    }*/
    ft_putnbr(ret);
    if (ret == -1 && solved != 1)
    {
        ft_putendl("Terminator-Gunde says: Tajm to bakktrakk.");
        print_map(map);
        free_map(map);
        solve(head, newlines, max, n + 1, start);
    }
    if (ret != -1)
    {
        ft_putstr("MAP SOLVED, MADDAFAKKA. Tetros placed:");
        ft_putnbr(placed);
        ft_putendl("");
        solved = 1;
    }
    ft_putendl("Reached end of solve function, going to main.");
    if (ret == 0)
        print_map(map);
}