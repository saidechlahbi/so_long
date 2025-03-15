

#ifndef SO_LONG_H
#define SO_LONG_H

#include "/usr/include/minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <fcntl.h>

typedef struct s_player{
    int x;
    int y;
    int p_count;
} t_player;

typedef struct s_game
{
    void *mlx;
    void *window;
    void *img_player;
    void *img_collect;
    void *img_wall;
    void *img_floor;
    void *img_exit;
    int c_count;
    int e_cout;
    char **maps;
    int map_lenght;
    int map_width;
    t_player player;
    char *av;
} t_game;

/*tools*/
void	ft_putstr_fd(char *s, int fd);
int ft_strlines(char **str);
void	*ft_memset(void *s, int c, size_t n);

/*check file*/

/*check maps*/
void read_the_maps(t_game *game);
void filter_maps(t_game *game);


/* clean */
void ft_clean_strings(char **strings);
void out(char *str, t_game *game);

/* get next line*/
char	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_last_rest_of_line(char *str);
char	*get_rest_for_next_line(char *str);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif