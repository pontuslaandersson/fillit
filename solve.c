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

void    solve(t_piece *head, int newlines, int max)
{
    static char     **map;
    int             ret;
    static int      solved;
    t_piece         *cursor;
    int             n;
    
    solved = 0;
    ft_putstr("Max: ");
    ft_putnbr(max);
    ft_putendl("");
    map = initialize_map(newlines);
    ft_putendl("Sending to place_first...");
    ret = place_first(head, map);
    while (ret == -1)
    {
        free_map(map);
        newlines = newlines + 5;
        map = initialize_map(newlines);
        ret = place_first(head, map);
    }
    /*if (placed > 0)
    {
        while (placed < max)
        {
            ft_putendl("Sending to place_piece...");
            ret = place_piece(head, map, placed, n, start);
            if (ret == -1)
                break ;
            ++placed;
        }
    }*/
    /*ret = solve_map(head, map);*/
    while (solve_map(head, map) == -1)
    {
        n = ft_strlen(map[0]);
        /*ft_putstr("Retrying with n: ");
        ft_putnbr(n);
        ft_putendl("");*/
        free_map(map);
        map = create_map(n + 1);
        ret = place_first(head, map);
     }
    /*if (ret == -2)
    {
        ft_putendl("Re-trying piece with increased position...");
        print_map(map);
        free_map(map);
        solve(head, newlines, max, n + 1, start);
    }*/
    /*if (ret == -1)
    {
        ft_putendl("Re-trying whole with larger map...");
        print_map(map);
        free_map(map);
        solve(head, newlines + 5, max, n, start);
    }*/
    ft_putnbr(ret);
    /*if (ret == -1 && solved != 1 )
    {
        ft_putendl("Re-trying piece with increased position...");
        print_map(map);
        free_map(map);
        solve(head, newlines, max, n + 1, start);
    }*/
    if (ret != -1)
    {
        ft_putendl("MAP SOLVED, MADDAFAKKA.");
        solved = 1;
    }
    ft_putendl("Reached end of solve function, going to main.");
    if (ret == 0)
        print_map(map);
}