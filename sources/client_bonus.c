#include "../includes/minitalk.h"

void	ft_connection(int id)
{
	if (id == SIGUSR1)
		write(1, "|||connected to the server|||\n", 30);
}

int	ft_send(int pid, char c)
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
				ft_term("<fail connection>", 1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_term("<fail connection>", 1);
		}
		i++;
		pos >>= 1;
		usleep(100);
	}
	return (1);
}

void	ft_send_pid(int pid_1, int pid_2, int pos)
{
	int	i;

	i = 0;
	while (i < 17)
	{
		if (pos & pid_2)
		{
			if (kill(pid_1, SIGUSR1) == -1)
				ft_term("<fail connection>", 1);
		}
		else
		{
			if (kill(pid_1, SIGUSR2) == -1)
				ft_term("<fail connection>", 1);
		}
		i++;
		pos >>= 1;
		usleep(100);
	}
}

int	ft_test_con(int pid_1)
{
	int	pid_2;
	int	pos;

	pos = 65536;
	pid_2 = getpid();
	ft_send_pid(pid_1, pid_2, pos);
	signal(SIGUSR1, ft_connection);
	usleep(100);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
		ft_term("args != 3", 1);
	pid = ft_atoi(argv[1]);
	if (pid < 0 || pid > 99998)
		ft_term("pid is'n valid", 1);
	ft_test_con(pid);
	usleep(100);
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
	write(1, "|||message send|||\n", 19);
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
	return (0);
}
