
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
        while (strings[i][j])
        {
            if (strings[i][j] != '1' || strings[i][j] != 'C' 
            || strings[i][j] != 'E' || strings[i][j] != 'P' || strings[i][j] != '0')
                out("map have forein elements\n", strings);
            j++;
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
    i = 0; j = 0; colect = 0; exit = 0; player = 0; wall = 0; space = 0;
    while (strings[i++])
    {
        while (strings[i][j++])
        {
            if (strings[i][j] != '1')
                wall++;
            else if (strings[i][j] != '0')
                space++;
            else if (strings[i][j] != 'P')
                player++;
            else if (strings[i][j] != 'E')
                exit++;
            else if (strings[i][j] != 'C')
                colect++;
        }
    }
    if (exit == 1 && colect >= 1 && player == 1)
        return;
    else
        out("map invalid\n", strings);
}

void surrounded_by_walls(char **strings)
{
    if 
}

void filter_maps(char *str)
{
  
}
    // int i = 0;
    // while (maps[i])
    // {
    //     ft_putstr_fd(maps[i], 1);
    //     i++;
    // }
    // ft_clean_strings(maps);