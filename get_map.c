
#include "so_long.h"

static void   check_file(t_game *game)
{
    int i;
    int j;
    char *string;

    string = ".ber";
    i = 0;
    j = 0;
    while (game->av[i])
        i++;
    while (string[j])
        j++;
    j--;
    i--;
    while(game->av[i] == string[j])
    {
        i--;
        j--;
    }
    if (j == -1 && i > -1)
        return ;
    else
    {
        ft_putstr_fd( "Error\nthe name of the map shoud be end with _.ber\n", 2);
        exit(1);
    }
}

static void  ft_lines(t_game *game)
{
    char *string;
    int lines;
    int fd;

    check_file(game);
    fd = open (game->av, O_RDONLY);
    if (fd == -1)
        exit(1);
    lines = 0;
    string = get_next_line(fd); 
    while (string)
    {
        lines++;
        free(string);
        string = get_next_line(fd);
    }
    close (fd);
    game->map_lenght =  lines;
}

void read_the_maps(t_game *game)
{
    int fd;
    char *string;
    int lines;
    char **map;


    ft_lines(game);
    map = malloc(sizeof(char *) * (game->map_lenght + 1));
    if (!map)
       exit(1);
    fd = open (game->av, O_RDONLY);
    if (fd == -1)
        exit(1);
    string = get_next_line(fd); 
    lines = 0;
    while (string)
    {
        map[lines] = string;
        lines++;
        string = get_next_line(fd);
    }
    map[lines] = NULL;
    close(fd);
    game->maps =  map;
}
