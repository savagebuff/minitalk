#include "../includes/minitalk.h"

static void	ft_if_i_eight(int *i, int *pos, int *c)
{
	*i = 0;
	*pos = 128;
	ft_putchar_fd(*c, 1);
	*c = 0;
}

static void	ft_put_sign(int id)
{
	static int	i;
	static int	c;
	static int	pos;

	if (id == -1)
	{
		i = 0;
		c = 0;
		pos = 128;
	}
	else if (id == SIGUSR1)
	{
		i++;
		c += pos;
		pos >>= 1;
	}
	else if (id == SIGUSR2)
	{
		i++;
		pos >>= 1;
	}
	if (i == 8)
		ft_if_i_eight(&i, &pos, &c);
}

int	main(void)
{
	int	pid;

	ft_put_sign(-1);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, ft_put_sign);
		signal(SIGUSR2, ft_put_sign);
	}
	return (0);
}
