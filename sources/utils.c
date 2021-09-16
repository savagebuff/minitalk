#include "../includes/minitalk.h"

void	ft_term(char *str, int fd)
{
	if (str != NULL)
	{
		write(fd, str, ft_strlen(str));
	}
	write (1, "\n", 1);
	exit(fd);
}
