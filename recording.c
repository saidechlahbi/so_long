/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recording.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:32:08 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/12 00:17:15 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/usr/include/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int handler(int key)
{
    if (key == 65307)
        exit(1);
    return 0;
}


int main(int ac, char **av)
{
    char *str[] = {  "1111111111111",
                     "1010111111011",
                     "1000000000001",
                     "1111111111111"};
    void *mlx;
    void *windows;
    void *image1;
    void *image2;
    
    
    mlx = mlx_init();
    if (!mlx)
        return (printf("nikmok\n"), 1);
    windows = mlx_new_window(mlx, 13 * 64, 4 * 64, "nikmok");
    if (!windows)
        return (printf("nikmok\n"), 1);
    //     int i = 640;
    //     int j;
    // while (i < 1280)
    // {
    //     j = 360;
    //     while (j < 720)
    //     {
    //         mlx_pixel_put(mlx, windows, i , j, 0xFFFFFFF);
    //         j++;
    //     }
    //     i++;
    // }
    // naruto = mlx_xpm_file_to_image(mlx, "naruto.xpm", &(int){640}, &(int){360});
    // mlx_put_image_to_window(mlx, windows, naruto, 640, 360);
    image1 = mlx_xpm_file_to_image(mlx, "1.xpm", &(int){64}, &(int){64});
    image2 = mlx_xpm_file_to_image(mlx, "0.xpm", &(int){64}, &(int){64});
    int i = 0;
    int j = 0;
    
    while (i < 4)
    {
        j = 0;
        while (j < 13)
        {
            if (str[i][j] == '1')
                mlx_put_image_to_window(mlx, windows, image1, j * 64, i * 64);
            else
                mlx_put_image_to_window(mlx, windows, image2, j * 64, i * 64);
            j++;
            
        }
        i++;
    }
    mlx_key_hook (windows, handler, NULL);
    mlx_loop(mlx);
    return 0;
}
