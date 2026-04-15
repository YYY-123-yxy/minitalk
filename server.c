#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	handler(int sig)
{
	static int				bit = 7;
	static unsigned char	c = 0;

	if (sig == SIGUSR1)
	{
		c |= (1 << bit);
		bit--;
	}
	else if (sig == SIGUSR2)
		bit--;
	if (bit == -1)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		c = 0;
		bit = 7;
	}
}

void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
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


