/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:50:20 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/15 12:19:53 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/LIBFT/libft.h"
#include "../lib/Printf/includes/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int		g_num_bit;

//	static pid_t			client_pid;
//	client_pid = 0;
//	if (client_pid != info->si_pid && info->si_pid != 0)
//		client_pid = info->si_pid;

static void	sig_action(int sig, siginfo_t *info, void *context)
{
	static unsigned char	byte;

	(void)info;
	(void)context;
	if (sig == SIGUSR2)
		byte |= 1;
	g_num_bit++;
	if (g_num_bit == 8)
	{	
		ft_putchar_fd(byte, 1);
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
	ft_printf("PID: %d\n", pid);
	signal.sa_sigaction = sig_action;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
