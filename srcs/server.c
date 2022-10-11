/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:50:20 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/11 14:11:09 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/LIBFT/libft.h"
#include "../lib/Printf/includes/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

/*static void	sig_action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		printf("%d\n", c);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}*/

static void	sig_action(int sig, siginfo_t *info, void *context)
{
	static pid_t	client_pid;

	client_pid = 0;
	(void)context;
	if (client_pid != info->si_pid && info->si_pid != 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		printf("Senyal rebuda correctament.\n");
	if (sig == SIGUSR2)
		printf("Senyal erronea.\n");
}

int main()
{
	int pid;

	struct sigaction signal;
	pid = getpid();
	printf("PID: %d\n", pid);
	signal.sa_sigaction = sig_action;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
