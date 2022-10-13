/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:50:20 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/13 18:49:03 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/LIBFT/libft.h"
#include "../lib/Printf/includes/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int		num_bit;

static void	sig_action(int sig, siginfo_t *info, void *context)
{
//	static pid_t			client_pid;
	static unsigned char	byte;

//	client_pid = 0;
	(void)info;
	(void)context;
//	if (client_pid != info->si_pid && info->si_pid != 0)
//		client_pid = info->si_pid;
	if (sig == SIGUSR2)
	{
		byte &= 1;
		ft_printf("valor:%d\n", byte);
	}
	num_bit++;
	byte <<= 1;
	if (num_bit == 8)
	{	
		ft_putchar_fd(byte, 1);
		num_bit = 0;
	}
}

/*	if (sig == SIGUSR1)
		printf("0\n");
	if (sig == SIGUSR2)
		printf("1\n");
*/

int main()
{
	int pid;

	num_bit = 0;
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
