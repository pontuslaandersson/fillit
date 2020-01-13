
void    solve(t_piece *head, int newlines)
{
    char    **map;
    int     ret;
    int     placed;
    
    placed = 0;
    map = initialize_map(newlines);
    ret = place_piece(head, map, placed);
    
}