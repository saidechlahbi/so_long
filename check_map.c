
#include "so_long.h"
void out(char *str, char **strings)
{
    ft_clean_strings(strings);
    ft_putstr_fd(str, 2);
    exit(1);   

}

void elements(char **strings)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (strings[i])
    {
        j = 0;
        while (strings[i][j])
        {
            if (strings[i][j] == '1' || strings[i][j] == 'C' 
                || strings[i][j] == 'E' || strings[i][j] == 'P' 
                || strings[i][j] == '0')
                j++;
            else
                out("map have forein elements\n", strings);
        }
        i++;
    }
}

void nb_elements(char **strings)
{
    int i;
    int j;
    int colect;
    int exit;
    int player;
    int wall;
    int space;
    i = 0; colect = 0; exit = 0; player = 0; wall = 0; space = 0;
    while (strings[i])
    {
        j = 0;
        while (strings[i][j])
        {
            if (strings[i][j] =='1')
                wall++;
            else if (strings[i][j] =='0')
                space++;
            else if (strings[i][j] =='P')
                player++;
            else if (strings[i][j] =='E')
                exit++;
            else if (strings[i][j] =='C')
                colect++;
            j++;
        }
        i++;
    }
    if (exit == 1 && colect >= 1 && player == 1)
    return;
    else
        out("map invalid, some items do not meet the requirements\n", strings);
}

void nb_lines(char **strings)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(strings[0]);
    if (ft_strlines(strings) < 3)
        out("map invalid, must be at least 3 lines\n", strings);
    while (strings[i])
    {
        if (ft_strlen(strings[i]) != size)
            out("map invalid, all lines must be the same size\n", strings);
        i++;
    }
}
void surrounded_by_walls(char **strings)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (strings[i][j] && strings[i][j] == '1')
        j++;
    if (strings[i][j])
        out("map invalid, the map must be surrounded by walls\n", strings);
    j = 0;
    while (strings[i])
    {
        if (strings[i + 1] == NULL)
            break;
        if (strings[i][0] != strings[i][ft_strlen(strings[i]) - 1])
            out("map invalid, the map must be surrounded by walls\n", strings);
        i++;
    }
    j = 0;
    while (strings[i][j] && strings[i][j] == '1')
        j++;
    if (strings[i][j])
        out("map invalid, the map must be surrounded by walls\n", strings);
}

void  flood_fill(char **tab, int x, int y)
{
    if (tab[x][y] == '1')
        return;
    tab[x][y] == 'F';
    fill(tab, x + 1, y);
    fill(tab, x, y + 1);
    fill(tab, x, y - 1);
    fill(tab, x - 1, y);
}

void filter_maps(char *str)
{
    char **strings;
    char **strings1;

    strings = read_the_maps(str);
    elements(strings);
    nb_elements(strings);
    nb_lines(strings);
    surrounded_by_walls(strings);
    strings1 = read_the_maps(str);


    flood_fill(strings1, 1, 4);
    // int i = 0;
    // while (strings1[i])
    // {
    //     ft_putstr_fd(strings1[i], 1);
    //     i++;
    // }
}