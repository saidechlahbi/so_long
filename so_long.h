

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <fcntl.h>


/*tools*/
void	ft_putstr_fd(char *s, int fd);


/*check file*/
void   check_file(char *str);

/*check maps*/


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
#  define BUFFER_SIZE 10
# endif

#endif