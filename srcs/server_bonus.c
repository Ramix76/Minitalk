/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:34:40 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/19 12:35:28 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/LIBFT/libft.h"
#include "../lib/Printf/includes/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int		g_num_bit;

static void	sig_action(int sig, siginfo_t *info, void *context)
{
	static unsigned char	byte;

	(void)context;
	usleep(100);
	if (sig == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	if (sig == SIGUSR2)
	{
		byte |= 1;
		kill(info->si_pid, SIGUSR1);
	}
	g_num_bit++;
	if (g_num_bit == 8)
	{	
		ft_putchar_fd(byte, 1);
		if (byte == '\0')
			kill(info->si_pid, SIGUSR2);
		g_num_bit = 0;
	}
	byte <<= 1;
}

int	main(void)
{
	int					pid;
	struct sigaction	signal;

	g_num_bit = 0;
	pid = getpid();
	if (ft_printf("PID: %d\n", pid) == -1)
		exit (-1);
	signal.sa_sigaction = sig_action;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}