

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

int ft_strlines(char **str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return len;
}