/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:35:22 by aabel             #+#    #+#             */
/*   Updated: 2023/05/10 13:54:04 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	g_bool = 0;

void	send_bit(int pid, char str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < 8)
	{
		result = str % 2;
		if (result == 0)
			kill(pid, SIGUSR1);
		else if (result == 1)
			kill(pid, SIGUSR2);
		str = str / 2;
		i++;
		pause();
		usleep(10);
	}
}

void	send_bit_32(int pid, char str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < 32)
	{
		result = str % 2;
		if (result == 0)
			kill(pid, SIGUSR1);
		else if (result == 1)
			kill(pid, SIGUSR2);
		str = str / 2;
		i++;
		pause();
		usleep(10);
	}
}

void	confirmed(int sig, siginfo_t *info, void *content)
{
	(void) info;
	(void) content;
	(void) sig;
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	s_sigaction;
	int					u;

	i = 0;
	u = 0;
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	s_sigaction.sa_sigaction = confirmed;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	u = ft_strlen(argv[2]);
	send_bit_32(pid, u);
	while (argv[2][i])
		send_bit(pid, argv[2][i++]);
	send_bit(pid, 0);
	return (0);
}
