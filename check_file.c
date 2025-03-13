
#include "so_long.h"

static void   check_file(char *str)
{
    int i;
    int j;
    char *string;

    string = ".ber";
    i = 0;
    j = 0;
    while (str[i])
        i++;
    while (string[j])
        j++;
    j--;
    i--;
    while(str[i] == string[j])
    {
        i--;
        j--;
    }
    if (j == -1 && i > -1)
        return ;
    else
    {
        ft_putstr_fd( "the name of the map shoud be end with _.ber\n", 2);
        exit(1);
    }
}

static int ft_lines(char *str)
{
    char *string;
    int lines;
    int fd;

    check_file(str);
    fd = open (str, O_RDONLY);
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
    return lines;
}

static char **read_the_maps(char *str)
{
    int fd;
    char *string;
    int lines;
    char **mapes;


    lines = ft_lines(str);
    printf("%d\n", lines);
    mapes = malloc(sizeof(char *) * (lines + 1));
    if (!mapes)
       exit(1);
    fd = open (str, O_RDONLY);
    if (fd == -1)
        exit(1);
    string = get_next_line(fd); 
    lines = 0;
    while (string)
    {
        mapes[lines] = string;
        lines++;
        string = get_next_line(fd);
    }
    mapes[lines] = NULL;
    close(fd);
    return mapes;
}

void filter_maps(char *str)
{
    char **strings;
    int i;
    int j;

    strings = read_the_maps(str);
    // int i = 0;
    // while (maps[i])
    // {
    //     ft_putstr_fd(maps[i], 1);
    //     i++;
    // }
    // ft_clean_strings(maps);
    if (ft_strlines(strings) < 3)
    {
        ft_clean_strings(strings);
        ft_putstr_fd("map invalid\n", 2);
        exit(1);   
    }
    i =0;
    j = 0;
    while (strings[i])
    {
        while (strings[i][j])
        {
            if (strings[i][j] != '1' || strings[i][j] != 'C' 
            || strings[i][j] != 'E' || strings[i][j] != 'P')
            {
                ft_clean_strings(strings);
                exit(1);
            }
            j++;
        }
        i++;
    }
    i = 0;
    j = 0;
    int collectibles;
    int exit;
    int player;
    while (strings[i])
    {
        while (strings[i][j])
        {
            if (strings[i][j] != '1')
                
                 || strings[i][j] != 'C' 
            || strings[i][j] != 'E' || strings[i][j] != 'P')
            {
                ft_clean_strings(maps);
                exit(1);
            }
            j++;
        }
        i++;
    }
}
