#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_mess
{
	int	i;
	int	c;
	int	ready;
	int	pos;
}				t_mess;

void	ft_term(char *str, int fd);

#endif