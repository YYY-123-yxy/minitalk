#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	handler(int sig, siginfo_t *info, void *context)
{
	static int		bit = 7;
	static unsigned char	c = 0;
	(void)context;

	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit--;
	if (bit == -1)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bit = 7;
	}
	if (info -> si_pid > 0)
		kill(info->si_pid, SIGUSR1);
}

void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	setup_signals();
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}


