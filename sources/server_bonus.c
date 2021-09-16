#include "../includes/minitalk.h"

static void	ft_res_mess(t_mess *mess)
{
	if (mess->i == 8 && mess->ready)
	{
		mess->i = 0;
		mess->pos = 128;
		if (mess->c == 0)
		{
			mess->ready = 0;
			mess->pos = 65536;
		}
		ft_putchar_fd(mess->c, 1);
		mess->c = 0;
	}
	else if (mess->i == 17 && !mess->ready)
	{
		write(1, "\nnew mess:\n", 11);
		usleep(200);
		kill(mess->c, SIGUSR1);
		mess->ready = 1;
		mess->c = 0;
		mess->i = 0;
		mess->pos = 128;
	}
}

static void	ft_put_sign(int id)
{
	static t_mess	mess;

	if (id == -1)
	{
		mess.i = 0;
		mess.c = 0;
		mess.pos = 65536;
		mess.ready = 0;
		return ;
	}
	else if (id == SIGUSR1)
	{
		mess.c += mess.pos;
		mess.i++;
		mess.pos >>= 1;
	}
	else if (id == SIGUSR2)
	{
		mess.i++;
		mess.pos >>= 1;
	}
	ft_res_mess(&mess);
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
