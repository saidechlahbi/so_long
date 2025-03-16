
#include "so_long.h"



void out(char *str, t_game *game)
{
     clean_game(game);
    // ft_clean_strings(strings);
    if (str)
        ft_putstr_fd(str, 2);
    exit(1);   

}

void elements(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (game->maps[i])
    {
        j = 0;
        while (game->maps[i][j])
        {
            if (game->maps[i][j] == '1' || game->maps[i][j] == 'C' 
                || game->maps[i][j] == 'E' || game->maps[i][j] == 'P' 
                || game->maps[i][j] == '0')
                j++;
            else
                out("map have forein elements\n", game);
        }
        i++;
    }
}

void nb_elements(t_game *game)
{
    int i;
    int j;
  
    i = 0;
    while (game->maps[i])
    {
        j = 0;
        while (game->maps[i][j])
        {
            if (game->maps[i][j] =='P')
                game->player.p_count++;
            else if (game->maps[i][j] =='E')
                game->e_cout++;
            else if (game->maps[i][j] =='C')
                game->c_count++;
            j++;
        }
        i++;
    }
    if (game->player.p_count == 1 && game->c_count && game->e_cout == 1)
        return;
    else
        out("map invalid, some items do not meet the requirements\n", game);
}

void nb_lines(t_game *game)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(game->maps[0]);
    game->map_width = size;
    if (game->map_lenght < 3)
        out("map invalid, must be at least 3 lines\n", game);
    while (game->maps[i])
    {
        if (ft_strlen(game->maps[i]) != size)
            out("map invalid, all lines must be the same size\n", game);
        i++;
    }
}
void surrounded_by_walls(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (game->maps[i][j] && game->maps[i][j] == '1')
        j++;
    if (game->maps[i][j])
        out("map invalid, the map must be surrounded by walls\n", game);
    j = 0;
    while (game->maps[i])
    {
        if (game->maps[i + 1] == NULL)
            break;
        if (game->maps[i][0] != '1' || game->maps[i][ft_strlen(game->maps[i]) - 1] != '1')
            out("map invalid, the map must be surrounded by walls\n", game);
        i++;
    }
    j = 0;
    while (game->maps[i][j] && game->maps[i][j] == '1')
        j++;
    if (game->maps[i][j])
        out("map invalid, the map must be surrounded by walls\n", game);
}

void  flood_fill(char **tab, int x, int y)
{
    if (tab[x][y] == '1' || tab[x][y] == 'F')
        return;
    tab[x][y] = 'F';
    flood_fill(tab, x + 1, y);
    flood_fill(tab, x, y + 1);
    flood_fill(tab, x, y - 1);
    flood_fill(tab, x - 1, y);
}

void get_player_position(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->maps[i])
    {
        j = 0;
        while (game->maps[i][j])
        {
            if (game->maps[i][j] == 'P')
            {
                game->player.y = i;
                game->player.x = j;
                return ;
            }
            j++;
        }
        i++;
    }
}

void   check_path(t_game *game)
{
    int i;
    int j;

    i = 0;
    flood_fill(game->maps, game->player.x, game->player.y);

    while (game->maps[i])
    {
        j = 0;
        while (game->maps[i][j])
        {
            if (game->maps[i][j] == 'C' || game->maps[i][j] == 'E')
                out("map invalid, the map must be surrounded by walls\n", game);
            j++;
        }
        i++;
    }
}                                                                                                                                                                                                                                                                                                                                                                                          
void filter_maps(t_game *game)
{
    read_the_maps(game);
    elements(game);
    nb_elements(game);
    nb_lines(game);
    surrounded_by_walls(game);
    get_player_position(game);
    check_path(game);
    read_the_maps(game);

}