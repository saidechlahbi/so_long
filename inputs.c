/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:20:54 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/18 01:43:35 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_move_player(t_game *game, int x, int y)
{
    int new_x;
    int new_y;

    new_x = game->player.x + x;
    new_y = game->player.y + y;
    if (game->maps[new_y][new_x] == '1')
        return ;
    else if (game->maps[new_y][new_x] == 'C')
        game->c_count--;
    else if (game->maps[new_y][new_x] == 'E')
    {
        if (game->c_count == 0)
        {
            ft_putstr_fd("You win\n", 1);
            mlx_loop_end(game->mlx);
            out(NULL, game);
        }
        return ;
    }
    game->maps[game->player.y][game->player.x] = '0';
    game->player.x = new_x;
    game->player.y = new_y;
    game->maps[game->player.y][game->player.x] = 'P';
    printf("move number == %d\n", game->player.p_steps++);
    rander_map(game);
}

int handel(int key, t_game *game)
{
    if (key == KEY_ESC)
    {
        out("game over\n", game);
        mlx_loop_end(game->mlx);
        exit(1);
    }
    if (key == KEY_LEFT)
        ft_move_player(game, -1, 0);
    else if (key == KEY_RIGHT)
        ft_move_player(game, 1, 0);
    else if (key == KEY_UP)
        ft_move_player(game, 0, -1);
    else if (key == KEY_DOWN)
        ft_move_player(game, 0, 1); 
    return 0;
}
