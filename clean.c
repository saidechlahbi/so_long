
#include "so_long.h"
 
void ft_clean_strings(char **strings)
{
    int i;

    i = 0;
    while (strings[i])
    {
        free(strings[i]);
        i++;
    }
    free(strings);
}