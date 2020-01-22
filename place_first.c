#include "fillit.h"

int     place_first(t_piece *head, char **map)
{
    int         x;
    int         y;
    int         hash;
    int         j;

    x = 0;
    y = 0;
    /*y = (n / (ft_strlen(map[0])));
    x = (n % (ft_strlen(map[0])));*/
    ft_putnbr(x);
    ft_putchar('\n');
    ft_putnbr(y);
    hash = 0;
    j = 1;
    
    ft_putendl("Checking for negatives...");
    if (head->x[0] < 0 || head->x[1] < 0 || head->x[2] < 0)
    {
        while (((head->x[0] + x) < 0 || (head->x[1] + x) < 0 || (head->x[2] + x) < 0) && map[y][x] != '\0'/*there's enough map*/)
        ++x;
    }
    ft_putnbr(head->x[0] + x + 1);
    if ((head->x[0] + x + 1) > ft_strlen(map[0]) || (head->x[1] + x + 1) > ft_strlen(map[0]) || (head->x[2] + x + 1) > ft_strlen(map[0]) || (head->y[0] + y + 1) > ft_strlen(map[0]) || (head->y[1] + y + 1) > ft_strlen(map[0]) || (head->y[2] + y + 1) > ft_strlen(map[0]))
    {
        ft_putendl("We're going to need a bigger map...");
        return (-1);
    }
    ft_putendl("Placing our first hash.");
    map[y][x] = head->letter;
    while (hash < 3)
    {
        ft_putendl("Placing hash...");
        if (map[head->y[hash] + y][head->x[hash] + x] == '.')
        {
            map[head->y[hash] + y][head->x[hash] + x] = head->letter;
            ft_putendl("Hash successfully placed.");
            print_map(map);
        }
        else
        {
            ft_putstr("Placement unsuccessful at x = ");
            ft_putnbr(head->x[hash] + x);
            ft_putstr(" and y = ");
            ft_putnbr(head->y[hash] + y);
            ft_putendl(".");
        }
        ++hash;
    }
    ft_putendl("Hashes placed...");
    return (0);
}