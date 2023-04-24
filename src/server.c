/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:28:37 by aabel             #+#    #+#             */
/*   Updated: 2023/04/24 14:51:02 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, usr1);
	signal(SIGUSR2, usr2);
	pause();
	return (0);
}

void	usr1(int sig)
{
	(void) sig;
	ft_printf("j ai bien recu ta merde 1\n");
}

void	usr2(int sig)
{
	(void) sig;
	ft_printf("j ai bien recu ta merde 2\n");
}
