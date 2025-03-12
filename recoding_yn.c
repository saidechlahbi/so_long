/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recoding_yn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:18:07 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/12 01:21:44 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/usr/include/minilibx-linux/mlx.h"
#include <stdlib.h>

int handle()
{
    
    exit(0);
    
}
int main ()
{
    void *mlx;
    void *window;
    char *str[] = {
        "11111111111",
        "10000100001",
        "10000100001",
        "10000100001",
        "11111111111",
        NULL
    };

    mlx = mlx_init();
    if (!mlx)
        return 0;
    window = mlx_new_window(mlx, 64 * 11, 64 * 5, "youness laarare");
    if (!window)
        return 0;
    // int xc = 960 / 3;
    // int yc = 1080 / 3;
    // int x = xc;
    // while (x < xc * 2)
    // {
    //     mlx_pixel_put(mlx, window, x, yc , 0xFFFFFFF);
    //     x++;
    // }
    // x = xc;
    // while (x < xc * 2)
    // {
    //     mlx_pixel_put(mlx, window, x, yc * 2 , 0xFFFFFFF);
    //     x++;
    // }
    // x = yc;
    // while (x < yc * 2)
    // {
    //     mlx_pixel_put(mlx, window, xc, x , 0xFFFFFFF);
    //     x++;
    // }
    //     x = yc;
    // while (x < yc * 2)
    // {
    //     mlx_pixel_put(mlx, window, xc * 2, x , 0xFFFFFFF);
    //     x++;
    // }
    void *text1 = mlx_xpm_file_to_image(mlx, "0.xpm", &(int){64}, &(int){64});
    void *text2 = mlx_xpm_file_to_image(mlx, "1.xpm", &(int){64}, &(int){64});
    void *naroto = mlx_xpm_file_to_image(mlx, "naruto.xpm", &(int){640}, &(int){360});
    int y;
    int x;
    x = 0;
    while (str[x])
    {
        y = 0; 
        while (str[x][y])
        {
            if (str[x][y] == '1')
                mlx_put_image_to_window(mlx, window, text2, y * 64, x * 64);
            else
                mlx_put_image_to_window(mlx, window, text1, y * 64, x * 64);
            y++;
        }
        x++;
    }
    mlx_hook(window, 17, 0, handle, NULL);
    mlx_loop(mlx);
}