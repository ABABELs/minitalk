/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:35:22 by aabel             #+#    #+#             */
/*   Updated: 2023/05/04 14:29:52 by aabel            ###   ########.fr       */
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
		usleep(50);
	}
}

void	error(int sig, siginfo_t *info, void *content)
{
	(void) info;
	(void) content;
	if (sig == SIGUSR1)
		g_bool = 1;
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	s_sigaction;

	i = 0;
	pid = ft_atoi(argv[1]);
	s_sigaction.sa_sigaction = error;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	if (argc != 3)
		return (0);
	while (argv[2][i])
	{
		if (g_bool == 1)
			break ;
		send_bit(pid, argv[2][i++]);
	}
	if (g_bool == 0)
		send_bit(pid, 0);
	return (0);
}