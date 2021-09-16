#include "../includes/minitalk.h"

static int	ft_send_message(int pid, char c)
{
	int	i;
	int	pos;

	i = 0;
	pos = 128;
	while (i < 8)
	{
		if (pos & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_term("pid is'n valid", 1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_term("pid is'n valid", 1);
		}
		i++;
		pos >>= 1;
		usleep(100);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
		ft_term("args != 3", 1);
	pid = ft_atoi(argv[1]);
	if (pid < 1 || pid > 99998)
		ft_term("pid is'n valid", 1);
	i = 0;
	while (argv[2][i])
	{
		ft_send_message(pid, argv[2][i]);
		i++;
	}
	return (0);
}
