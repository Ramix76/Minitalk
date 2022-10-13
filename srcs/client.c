/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:37:58 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/13 17:05:28 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/LIBFT/libft.h"
#include "../lib/Printf/includes/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

/*void	sending(int sig, siginfo_t *info, void *uap)
{
}*/
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
		server_pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send_byte(argv[2][i], server_pid);
			i++;
		}
	send_byte('\0', server_pid);
	}
	return (0);
}
