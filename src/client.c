/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:35:22 by aabel             #+#    #+#             */
/*   Updated: 2023/04/24 15:08:34 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	kill(ft_atoi(argv[1]), SIGUSR1);
	kill(ft_atoi(argv[1]), SIGUSR2);
	return (0);
}

void	send_char(char *str)
{
	int	i;

	i = 0;
	while (i > 0)
	{
		
	}
}