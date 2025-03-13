
#include "so_long.h";
#include <time.h>

void   check_file(char *str)
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
        ft_putstr_fd( "the name of the map shoud be end with .ber\n", 2);
        exit(1);
    }
}

char **read_the_maps(char *str)
{
    int fd;
    char *string;
    int lines;
    char **mapes;

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
    mapes = malloc(sizeof(char *) * lines + 1);
    if (!mapes)
       exit(1);
    close(fd); 
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
    return mapes;
}
