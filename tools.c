/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recording.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:32:08 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/15 15:46:25 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	initialisation(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_wall = NULL;
	game->c_count = 0;
	game->e_cout = 0;
	game->maps = 0;
	game->map_lenght = 0;
	game->map_width = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.p_count = 0;
	game->player.p_steps = 0;
	game->lbaaab = NULL;
}

// int	ft_putnbr(int n)
// {
// 	char	c;
// 	int		count;

// 	count = 0;
// 	if (n == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 		return (11);
// 	}
// 	if (n < 0)
// 	{
// 		count += write(1, "-", 1);
// 		n = -n;
// 	}
// 	if (n > 9)
// 		count += ft_putnbr(n / 10);
// 	c = (n % 10) + '0';
// 	count += ft_putchar(c);
// 	return (count);
// }