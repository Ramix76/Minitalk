/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:37:58 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/17 19:09:36 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/LIBFT/libft.h"
#include "../lib/Printf/includes/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	if (ft_printf("\r\e[1;34mSending [%d] bits\e[0m", received) == -1)
		exit (-1);
	if (sig == SIGUSR2)
	{
		if (ft_printf("\r\e[1;34mMessage finished at [%d] bits\e[0m", received) == -1)
			exit (-1);
		exit (EXIT_SUCCESS);
	}
}

void	send_byte(char byte, int pid)
{
	int			i;
	int			kill_response;
	int			signal;

	i = 0;
	while (i < 8)
	{
		if (byte & 0x80)
			signal = SIGUSR2;
		else
			signal = SIGUSR1;
		kill_response = kill(pid, signal);
		pause();
		if (kill_response < 0)
		{
			ft_putstr_fd("Signal error", 2);
			exit(-1);
		}
		usleep(300);
		byte <<= 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	if (argc == 3)
	{
		signal(SIGUSR1, action);
		signal(SIGUSR2, action);
		server_pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send_byte(argv[2][i], server_pid);
			i++;
		}
		send_byte('\0', server_pid);
		}
	else
		ft_putstr_fd("Invalid number of arguments", 2);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
