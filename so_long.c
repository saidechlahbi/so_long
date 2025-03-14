
#include "so_long.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(1, "Error\n",6 );
        return 0;
    }
    filter_maps(av[1]);
}