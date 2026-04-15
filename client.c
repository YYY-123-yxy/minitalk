/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:40:03 by ziyang            #+#    #+#             */
/*   Updated: 2026/04/15 21:30:58 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t	g_ack = 0;

void	handle_ack(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	safe_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("Error: server not found\n");
		exit(1);
	}
}

void	send_char(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ack = 0;
		if ((c >> bit) & 1)
			safe_kill(pid, SIGUSR1);
		else
			safe_kill(pid, SIGUSR2);
		while (!g_ack)
			pause ();
		bit--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <message>\n");
		return (1);
	}
	signal(SIGUSR1, handle_ack);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error: invalide PID\n");
		return (1);
	}
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
