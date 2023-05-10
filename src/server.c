/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:28:37 by aabel             #+#    #+#             */
/*   Updated: 2023/05/10 14:18:26 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	error(int *bit, int *i, char *str)
{
	*bit = 0;
	*i = 0;
	if (str)
		free(str);
}

void	ft_reception(int sig, siginfo_t *info, void *context)
{
	static int	bit = -1;
	static int	bit_len = 1;
	static char	*str = NULL;
	static int	u = 0;

	(void) info;
	(void) context;
	bit_len++;
	if (bit_len <= 32)
	{
		if (sig == SIGUSR2)
			u = u | (0x0001 << bit_len);
		if (bit_len == 32)
		{
			str = malloc(sizeof(char) * u);
			str[u - 1] = 0;
			bit_len++;
		}
	}
	else if (bit_len > 32)
		ft_reception_to_print(&bit_len, sig, &bit, str);
	(usleep(50), kill(info->si_pid, SIGUSR2));
}

void	ft_reception_to_print(int *bit_len, int sig, int *bit, char *str)
{
	static int	i = 0;

	if (sig == SIGUSR2)
		i = i | (0x01 << (*bit));
	(*bit)++;
	if ((*bit) == 8)
	{
		if (i >= 0x00 && i <= 0x7f)
		{
			str[(((*bit_len) - 32) / 8) - 1] = i;
		}
		else
			exit (0);
		if (i == 0)
		{
			ft_printf("%s\n", str);
			str = NULL;
			free(str);
			(*bit_len) = 0;
		}
		(*bit) = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	ft_printf("%d\n", pid);
	s_sigaction.sa_sigaction = ft_reception;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
	{
		pause();
	}
	return (0);
}
