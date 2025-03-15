
#include "so_long.h"
 
void clean_game(t_game *game)
{
    ft_clean_strings(game->maps);
    if (game->mlx)
    {
        if (game->img_collect)
            mlx_destroy_image(game->mlx, game->img_collect);
        if (game->img_player)
            mlx_destroy_image(game->mlx, game->img_player);
        if (game->img_exit)
            mlx_destroy_image(game->mlx, game->img_exit);
        if (game->img_wall)
            mlx_destroy_image(game->mlx, game->img_wall);
        if (game->img_floor)
            mlx_destroy_image(game->mlx, game->img_floor);
        if (game->window)
        {
            mlx_clear_window(game->mlx, game->window);
            mlx_destroy_window(game->mlx, game->window);
        }
        mlx_destroy_display(game->mlx);
    }
    free(game);
}

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
