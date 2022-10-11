/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:37:58 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/11 14:11:12 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/LIBFT/libft.h"
#include "../lib/Printf/includes/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>


void	sending(int sig, siginfo_t *info, void *uap)
{
	int	pid;

	(void)info;
	(void)uap;
	if (sig == SIGUSR1)
		kill(pid, SIGUSR1);
	if (sig == SIGUSR2)
		kill(pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	int	server_pid;
	struct sigaction	signal;

	if (argc == 3)
	{
		signal.sa_sigaction = sending;
		signal.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &signal, NULL);
		server_pid = ft_atoi(argc[1]);
		while (1)
			pause();
	}
	return (0);
}
