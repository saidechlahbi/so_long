

#ifndef SO_LONG_H
#define SO_LONG_H

// #include "/usr/include/minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <fcntl.h>

typedef struct s_node{
    int flood_x;
    int flood_y;

} t_node;



/*tools*/
void	ft_putstr_fd(char *s, int fd);
int ft_strlines(char **str);

/*check file*/

/*check maps*/
char **read_the_maps(char *str);
void filter_maps(char *str);


/* clean */
void ft_clean_strings(char **strings);

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