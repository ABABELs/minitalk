/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:35:22 by aabel             #+#    #+#             */
/*   Updated: 2023/05/31 17:20:06 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int		g_bool = 1;

void	nothing(int sig, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	(void) sig;
}

void	char_to_bit(int pid, char str)
{
	int	i;
	int	result;

	i = 8;
	result = 0;
	while (i > 0)
	{
		result = str % 2;
		if (result == 0)
			kill(pid, SIGUSR1);
		else if (result == 1)
			kill(pid, SIGUSR2);
		str = str / 2;
		i--;
		pause();
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	s_sigaction;

	i = 0;
	pid = ft_atoi(argv[1]);
	s_sigaction.sa_sigaction = nothing;
	s_sigaction.sa_flags = SA_SIGINFO;
	if (argc != 3)
		return (0);
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (argv[2][i])
		char_to_bit(pid, argv[2][i++]);
	char_to_bit(pid, 0);
	return (0);
}
